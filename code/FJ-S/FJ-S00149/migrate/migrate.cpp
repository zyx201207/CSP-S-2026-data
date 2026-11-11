#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,T,n,dep[N],w[N];
vector<int>e[N];
ll d,x[N];
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]),e[i].clear();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(abs(x[i]-x[j])<=d)
				e[i].push_back(j),e[j].push_back(i);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++)dep[k]=-1,w[k]=0;
		queue<int>q;
		q.push(i);
		w[i]=1;
		dep[i]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				if(dep[v]==-1){
					dep[v]=dep[u]+1;
					w[v]+=w[u];
					q.push(v);
				}else if(dep[v]==dep[u]+1){
					w[v]+=w[u];
				}
			}
		}
		for(int j=i+1;j<=n;j++)
			if(w[j]==2)ans++;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(;T--;){
		solve();
	}
}
