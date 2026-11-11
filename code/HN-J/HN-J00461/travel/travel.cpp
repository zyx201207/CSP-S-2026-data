#include<bits/stdc++.h>
using namespace std;
string R,X,Rz,Xz; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>R>>Rz>>X>>Xz;
	int rz=(Rz[0]-'0')*10+Rz[1],xz=(Xz[0]-'0')*10+Xz[1];
	int rid=Rz[2]-'A'+1,xid=Xz[2]-'A'+1;
	if(R==X){
		if(rz==xz){
			if((rid<=3&&xid<=3)||(rid>3&&xid>3)){
				if(abs(rid-xid)==1) cout<<"1111";
				else cout<<"1110"; 
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
