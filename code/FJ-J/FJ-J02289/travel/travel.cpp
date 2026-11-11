#include <bits/stdc++.h>
using namespace std;
#define endl /n
void solve(){
	string x,y,n,m;
	cin>>x>>y>>n>>m;
	if(x!=n){
		cout<<"0000";
		return;
	}else{
		cout<<1;
		if(y[0]==m[0]&&y[1]==m[1]){
			cout<<1;
			int p=0,q=0;
			int r=y[2],l=m[2];
			if(r>='A'&&r<='C'&&l>='A'&&l<='C'){
				p=1;
			}
			if(r>='D'&&r<='F'&&l>='D'&&l<='F'){
				q=1;
			}
			if(q==1||p==1){
				cout<<1;
				if(p==1&&(r==l+1||r==l-1)){
					cout<<1;
					return;
				}else{
					cout<<0;
					return;
				}
				if(q==1&&(r==l-2||r==l+2)){
					cout<<1;
					return;
				}else{
					cout<<0;
					return;
				}
			}else{
				cout<<"00";
				return;
			}
		}else{
			cout<<"000";
			return;
		}
	}
		
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
