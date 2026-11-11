#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6;
int c,t,n,k,ans,f[maxn],p[maxn],dis[maxn];
vector<int>v[maxn]; 
int find(int x){
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
void dfs(int x,int fa){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(p[y]||y==fa) continue;
		dis[y]=min(dis[y],dis[x]+1);
		dfs(y,x);
	}
}
void d(int x,int cnt){
	if(cnt>k) return;
	if(x>n){
		if(cnt<k) return;
		for(int i=1;i<=n;i++) f[i]=i,dis[i]=1e18;
		for(int i=1;i<=n;i++){
			if(p[i]) dis[i]=0;
			if(p[i]) dfs(i,-1);
			for(int j=0;j<v[i].size();j++){
				int l=v[i][j];
				if(p[l]&&p[i]){
					if(find(l)!=find(i)) f[find(l)]=find(i);
				}
			}
		}
		int res=0,F=0;
		for(int i=1;i<=n;i++) F+=(p[i]&&i==find(i)),res=max(dis[i],res);
		if(F<=2) ans=min(ans,res);
		return;
	}
	p[x]=0;
	d(x+1,cnt);
	p[x]=1;
	d(x+1,cnt+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x); 
		}
		if(n==k){
			cout<<0<<'\n';
			continue;
		} 
		if(n<=10||k<=2){
			d(1,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

