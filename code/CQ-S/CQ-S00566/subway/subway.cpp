#include<bits/stdc++.h>
#define N 505
#define M 500005
using namespace std;
namespace shan{
	typedef long long ll;
	int c,n,m,d,q,w[M];
	vector<pair<int,int>>to[M];
	ll e[N][N];
    signed main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			while(k--){
				int a,t;cin>>a>>t;
				to[a].push_back({i,t});
			}
		}
		memset(e,0x3f,sizeof e);
		for(int i=1;i<=n;i++)e[i][i]=0;
		for(int i=1;i<=m;i++)
			for(auto [a,b]:to[i])
				for(auto [c,d]:to[i])
					e[a][c]=e[c][a]=min(e[a][c],(ll)b+d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
		while(q--){
			ll ans=1e18;
			int s,t;cin>>s>>t;
			for(auto [a,b]:to[s])
				for(auto [c,d]:to[t])
					ans=min(ans,b+d+e[a][c]);
			cout<<ans+w[s]+w[t]<<'\n';
		}
		cerr<<"TIME:"<<clock()<<'\n';
		return 0;
	}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}

/*
g++ subway.cpp -o subway.exe -Wall -Wextra -static -std=c++14 -O2 
./subway.exe
*/