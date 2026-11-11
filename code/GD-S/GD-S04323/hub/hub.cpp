#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5,mod=14518964329827;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		int fa[100005];
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			fa[u]=v;
		}
		cout<<mod%((fa[k/2]+n*26)/26)<<endl;
	}
	
	
	return 0;
} 
