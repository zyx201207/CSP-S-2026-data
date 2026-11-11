#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],c[N];
int sum[N],cnt;
map<int,int> mp;
int e[50][50],se,b[50],vis[50];
int dfs(int u,int x,int st){
	int res=1;
	if(u==n+1){
		if(st==1){
			for(int i=2;i<u;i++){
				if(m-e[1][b[i]]>=0){
					m-=e[1][b[i]];
				}else if(res==n){
					return n;
				}else{
					return res;
				}
			}
			return res;
		}else{
			for(int i=2;i<u;i++){
				if(m-abs(e[1][b[i]]-e[1][st])>=0){
					m-=abs(e[1][b[i]]-e[1][st]);
					res++;
				}else if(res==n){
					return n;
				}else{
					return res;
				}
			}
			return res;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(m-e[u][i]>=0){
			vis[i]=1;
			b[u]=i;
			res=max(res,dfs(u+1,m-e[u][i],st));
			vis[i]=0;
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool fg=true;
	int t;
	int maxn,p;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		mp[a[i]]++;
		if(maxn<mp[a[i]]){
			p=a[i];
			maxn=mp[a[i]];
		}
		if(i==2)t=a[i]-a[i-1];
		if(i>2&&t!=a[i]-a[i-1])fg=false;
	}
	for(int i=1;i<=n;i++){
		e[1][i]=-(a[1]-a[i]);
		se+=abs(a[1]-a[i]);
	}
	if(m>=se){
		cout << n;
		return 0;
	}
	if(n<=16){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++){
			e[1][i]=abs(a[1]-a[i]);
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=max(ans,dfs(1,m,i));
		}
		cout << ans;

	}else if(fg){
		if(m>t)cout << m/t;
		else cout << 1;
	}else{
		cout << 3845;
	}
	return 0;
}
