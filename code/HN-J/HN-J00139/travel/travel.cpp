#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	std::ios::sync_with_std(false);
//	cin.tie(nullptr);
	string n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<1;
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<1;
			if(m[2]=='A'||m[2]=='B'||m[2]=='C'){
				if(y[2]=='D'||y[2]=='F'){
					cout<<"00";
				}
				else{
				
					cout<<1;
					if(char(m[2]-1)!=y[2]&&char(m[2]+1)!=y[2]){
						cout<<0;
					}
					else{
						if(m[2]=='D'&&y[2]=='C'||m[2]=='C'&&y[2]=='D'){
							cout<<0;
						}
						else{
							cout<<1;
						}
				
					}
				}
			}
			else{
				if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
					cout<<"00";
				}
				else{
					cout<<1;
					if(char(m[2]-1)!=y[2]&&char(m[2]+1)!=y[2]){
						cout<<0;
					}
					else{
						if(m[2]=='D'&&y[2]=='C'||m[2]=='C'&&y[2]=='D'){
							cout<<0;
						}
						else{
							cout<<1;
						}
					}
				}
			}
		
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
	
	
}
