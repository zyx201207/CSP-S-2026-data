#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;

signed main();
void solve();

int x[maxn];
vector<int>g[maxn];
int f[maxn];

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
#ifndef local
	freopen("migrate.in" ,"r",stdin ),
	freopen("migrate.out","w",stdout);
#endif
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}

void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		g[i].clear();
		f[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d)break;
			g[i].push_back(j);
		}
		if(g[i].empty())f[i]=i;
		else f[i]=*g[i].rbegin();
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int k=0;
			for(int p=i;p<j;p=f[p]){
				if(p==f[p]){
					k=-1;
					break;
				}
				k++;
			}
			if(k==-1)break;
			queue<pair<int,int>>p;
			p.push({i,0});
			int cnt=0;
			while(!p.empty()){
				auto tmp=p.front();
				p.pop();
				int u=tmp.first,s=tmp.second;
				if(u==j&&s==k){
					if(++cnt<=2)continue;
					else break;
				}
				else if(u==j||s==k)continue;
				for(int v:g[u])p.push({v,s+1});
			}
			ans+=(cnt==2);
		}
	}
	cout<<ans<<"\n";
}
