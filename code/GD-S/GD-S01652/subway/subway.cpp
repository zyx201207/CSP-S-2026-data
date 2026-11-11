#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[500010];
struct node{
	long long wi;
	long long op;
};
vector<node>o[500010];
int vis[500010];
long long dis[500010];
long long a[500010],t[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int kl=j+1;kl<=k;kl++){
				o[a[j]].push_back({t[j]+t[kl],a[kl]});;
				o[a[kl]].push_back({t[j]+t[kl],a[j]});
			}
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		queue<int>q;
		q.push(x);
		vis[x]=0;
		dis[x]=w[x];
		long long nans=10000000000;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u==y){
				cout<<min(dis[u]+w[u],nans)<<'\n';
				break;
			}
			for(int i=0;i<o[u].size();i++){
				if(o[u][i].op==y){
					nans=dis[u]+o[u][i].wi+w[y];
					break;
				}
			}
			for(int i=0;i<o[u].size();i++){
				if(vis[o[u][i].op]==0){
					dis[o[u][i].op]=dis[u]+o[u][i].wi;
					vis[o[u][i].op]=1;
					q.push(o[u][i].op);
				}
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=0;
			dis[i]=0;
		}
	}
	return 0;
}
