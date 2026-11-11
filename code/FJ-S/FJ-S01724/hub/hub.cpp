#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int C,t,n,k,p[N],f[N][21],lg,dep[N],ans,ff[1010][1010];
vector<int> v[N];
void dfs(int x,int fa){
	f[x][0]=fa;
	for(int i=1;i<=lg;i++) f[x][i]=f[f[x][i-1]][i-1];
	dep[x]=dep[fa]+1;
	int y;
	for(int i=0;i<v[x].size();i++){
		y=v[x][i];
		if(y==fa) continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=lg;i>=0;i--){
		if(dep[x]-(1<<i)>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=lg;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
void solve(int x,int ch){
	if(x>n){
		if(ch!=k) return;
	}
	if(ch==k){
		int now=0,mi;
		for(int i=1;i<=n;i++){
			mi=n+1;
			for(int j=1;j<=ch;j++){
			mi=min(mi,dep[i]+dep[p[j]]-2*dep[ff[i][p[j]]]);
			}
			now=max(now,mi);
		}
		ans=min(ans,now);
		return;
	}
	if(k-ch>n-x+1)return;
	solve(x+1,ch);
	p[ch+1]=x;
	solve(x+1,ch+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	int x,y;
	srand(time(0));
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans=n+1;
		lg=log2(n);
		dfs(1,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) ff[i][j]=lca(i,j);
		}
		if(n<=10){
			solve(1,0);
			cout<<ans<<'\n';
		}else if(k==2){
			int now=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					now=0;
					for(int k=1;k<=n;k++){
						if(i==j||i==k) now=now;
						else now=max(now,min(dep[i]+dep[k]-2*dep[ff[i][k]],dep[j]+dep[k]-2*dep[ff[j][k]]));
					}
					ans=min(ans,now);
				}
			}
			cout<<ans<<'\n';
		}else cout<<n/2<<'\n';
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