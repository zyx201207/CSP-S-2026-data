//GZ-J00340 贵阳市华麟学校 张程清 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x;
	cin>>m>>y;
	if(n==m){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C')&&x[2]!=y[2]){
				cout<<1;
			}else if((x[2]=='D'||x[2]=='F')&&(y[2]=='D'||y[2]=='F')&&x[2]!=y[2]){
				cout<<1;
			}else{
				cout<<0;
			}
			if(x[2]=='A'&&y[2]=='B'){
				cout<<1;
			}else if(x[2]=='B'&&y[2]=='A'){
				cout<<1;
			}else if(x[2]=='B'&&y[2]=='C'){
				cout<<1;
			}else if(x[2]=='C'&&y[2]=='B'){
				cout<<1;
			}else if(x[2]=='D'&&y[2]=='F'){
				cout<<1;
			}else if(x[2]=='F'&&y[2]=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
		
	}else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
