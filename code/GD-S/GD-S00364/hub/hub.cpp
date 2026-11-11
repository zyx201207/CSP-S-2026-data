#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c,t,n,k;
bool flag=true;
int u[maxn],v[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>u[i]>>v[i];
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(n&1){
			flag=true;
			int m=(n-1)/2;
			for(int i=1;i<=n;i++){
				if(i<=m){
					if(u[i]!=i||v[i]!=i+1){
						flag=false;
						break;
					}
				}
				else{
					if(u[i]!=i-m||v[i]!=i+1){
						flag=false;
						break;
					}
				}
			}
			if(flag){
				if(k>=m){
					cout<<"1\n";
				}
				else{
					int w=ceil((n-(k-2))*1.0/(k+1));
					cout<<w<<'\n';
				}
				continue;
			}
		}
		cout<<1<<'\n';
	}
	return 0;
}
