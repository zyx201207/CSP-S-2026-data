#include<bits/stdc++.h>
using namespace std;
string r,rx,x,xr;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rx>>x>>xr;
	if(r==x){
		cout<<1;
		if(rx[1]==xr[1]&&rx[0]==xr[0]){
			cout<<1;
			if(rx[2]>='D'&&xr[2]>='D'||rx[2]<'D'&&xr[2]<'D'){
				cout<<1;
				if(rx[2]=='D'&&xr[2]=='F'||rx[2]=='F'&&xr[2]=='D'||rx[2]=='A'&&xr[2]=='B'||rx[2]=='B'&&xr[2]=='A'||rx[2]=='B'&&xr[2]=='C'||rx[2]=='C'&&xr[2]=='B'){
					cout<<1;
				}else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
} 
