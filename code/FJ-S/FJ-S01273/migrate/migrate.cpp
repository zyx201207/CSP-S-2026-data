#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
const int K=5e7+10;
int n,m,t,c;
int a[N];
int ver[K],nex[K],edge[K],head[K];
int tot,ans;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	nex[tot]=head[x];
	head[x]=tot;
}
int d[N],v[N],xx[N];
void bfs(int u){
	queue<int >q;
	q.push(u);
	d[u]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nex[i]){
			int y=ver[i],z=edge[i];
			if(d[x]+z<d[y]){
				d[y]=d[x]+z;
				xx[y]=1;
				q.push(y);
			}
			if(d[x]+z==d[y]) xx[y]++;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		} 
		if(a[n]-a[1]<m){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;++i){
			for(int j=i-1;j>=1;--j){
				if(a[i]-a[j]>m) break;
				add(j,i,1);
			}
		}
		ans=0;
		for(int i=1;i<=n;++i){
			memset(d,0x3f,sizeof(d));
			memset(v,0,sizeof(v));
			memset(xx,0,sizeof(xx));
			bfs(i);
			for(int j=1;j<=n;++j){
				if(xx[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
