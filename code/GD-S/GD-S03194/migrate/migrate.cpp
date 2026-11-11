#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+3;
int c,T;
int n,d; 
int a[N],nxt[N],tag[N],g[N];
int vis[N];
vector<int > f[N];
int bfs(int s){
	memset(vis,0,sizeof(vis));
	vector<int> now,later;
	now.push_back(s);
	vis[s]=1;
	int res=1;
	while(!now.empty()){
		swap(now,later);
		now.clear();
		for(int x:later){
			for(int v:f[x]){
				if(!vis[v]){
					now.push_back(v);
					res++;
					vis[v]=1;
				}
			}
		}
	} 
	return res;
}
void solve(){
	memset(tag,0,sizeof(tag));
	memset(g,0,sizeof(g));
	cin>>n>>d;
	for(int i=1;i<=n;i++){cin>>a[i];f[i].clear();}
	if(c>=10){
		cout<<0<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		int it=upper_bound(a+i,a+1+n,a[i]+d)-a-1;
		nxt[i]=it;
		f[it].push_back(i);
	}
	/*for(int i=n;i>=1;i--){
		int it=lower_bound(a+1,a+i,a[i]-d)-a;
		bnxt[i]=it;
	}*/
	for(int i=1;i<=n;i++){
		int x=nxt[i],y=x-1,z=x-2;
		if(x==n)continue;
		if(y>i){
			if(nxt[x]==x)continue;
			if(nxt[x]==nxt[y]){
				if(z<=i){
					tag[i]=1;
					g[i]=nxt[x];
					//cout<<i<<'\n';
				}
				if(z>i&&nxt[z]!=nxt[x]){
					tag[i]=1;
					g[i]=nxt[x];
					//cout<<i<<'\n';
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(tag[i]==1){
			//cout<<i<<'\n';
			int A=bfs(i);
			int res=n;
			for(int j=i+1;j<=n;j++){
				if(nxt[j]==j){
					res=j;
					break;
				}
				if(tag[j]==1){
					res=g[j]-1;
					break;
				}
			}
			ans+=A*(res-g[i]+1);
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
	return 0;
} 
