#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,x,b,y;
	cin>>a>>x>>b>>y;
	int a1=0,a2=0,a3=0,a4=0;
	if(a==b){
		a1=1;
	if(x[0]==y[0]&&x[1]==y[1]){
		a2=1;
		if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C')){
			a3=1;
			if(x[2]-1==y[2]||x[2]+1==y[2]){
				a4=1;
			}
				
		}
		if((x[2]=='D'||x[2]=='F')&&(y[2]=='D'||y[2]=='F')){
			a3=1;
			if(x[2]-1==y[2]||x[2]+1==y[2]){
				a4=1;
			}
				
		}
	
	}
	
	}
	
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
