#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,p[N],las[N],a[N],vis[N],siz[N];
vector<int>s[N],g[N];
int dfs(int x){
	if(siz[x])return siz[x];
	siz[x]=1;
	for(int t:g[x])siz[x]+=dfs(t);
	return siz[x];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(las[a[i]])g[i].push_back(las[a[i]]);
		las[a[i]]=i;s[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(i==las[a[i]]){
			for(int x:s[a[i]]){
				vis[x]=1;
				if(vis[x-1]&&x-1==las[a[x-1]])g[x].push_back(x-1); 
			}		
		}
	}
	for(int i=1;i<=m;i++)
		cout<<dfs(las[i])<<' ';
	return 0; 
}
