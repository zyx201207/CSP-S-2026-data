#include <iostream>
#include <string>
using namespace std;
int w[4]={0,0,0,0};
char q[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	int m=x[0]*10+x[1],n=y[0]*10+y[1];
	int o=0,c=0;
	if(a==b){
		w[0]=1;
		o++;
	}
	if(m==n&&o==1){
		w[1]=1;
		o++;
	}
	if(o==2){
		for(int i=0;i<2;i++){
			if(x[2]==q[i]||y[2]==q[i]){
				c++;
			}
		}
		if(c==2||c==0){
			w[2]=1;
		}
	}
	if(c==2&&o==2){
		w[3]=1;
	}
	else if(c==0&&o==2){
		if(x[2]=='B'||y[2]=='B'){
			w[3]=1;
		}
	}
	cout<<w[0]<<w[1]<<w[2]<<w[3];
	return 0; 
}
