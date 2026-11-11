#include<bits/stdc++.h>
using namespace std;
int q[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		q[0]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			q[1]=1;
			if(b[2]+1==d[2]||b[2]-1==d[2]){
				q[3]=1;
			}
			if(d[2]=='D'||b[2]=='D'&&b[2]=='F'||d[2]=='F'){
				q[3]=1;
			}
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'){
				q[2]=1;
			}
			if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F'){
				q[2]=1;
			}
			if(d[2]=='C'||b[2]=='C'&&d[2]=='D'||b[2]=='D'){
				q[3]=0;
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<q[i];
	}
	return 0;
}
