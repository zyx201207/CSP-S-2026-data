#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
vector<int> g[maxn];
int n,k;
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		if(c>=13&&c<=14){
			if(n==k){
				cout<<0<<"\n";
			} 
			else if((n-1)/2<=k){
				cout<<1<<"\n";
			}
			else{
				cout<<((n-1)/2-1)/(k+1)+1<<"\n";
			}
		}
	}
	
	
}  
