#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+5,M=5e5+5;
int c,n,m,d,q,w[M],z[M],e[M],dis[M];
vector<pair<int,int> > g[M];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>z[j]>>e[j];
			for(int l=1;l<j;l++) g[z[j]].push_back({z[l],e[j]+e[l]}),g[z[l]].push_back({z[j],e[j]+e[l]});
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		priority_queue<int> p;
		memset(dis,0x3f,sizeof(dis));
		p.push(x);dis[x]=0;
		while(p.size()){
			int t=p.top();p.pop();
			for(pair<int,int> o:g[t]){
				int i=o.first,w=o.second;
				if(dis[i]>dis[t]+w){
					dis[i]=dis[t]+w;
					p.push(i);
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	
	return 0;
}
