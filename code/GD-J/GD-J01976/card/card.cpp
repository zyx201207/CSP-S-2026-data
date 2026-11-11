#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],c[300005],f[300005];
vector<int>e[500005];
void dfs(int x,int fa){
	for(int i:e[x]){
		if(i==fa) continue;
		dfs(i,x);
		s[x]+=s[i];
	}
	if(a[x]!=-1) f[a[x]]+=s[x];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=1;
	for(int i=n;i>0;i--){
		if(c[a[i]]) e[c[a[i]]].push_back(i),a[i]=-1;
		else e[i+1].push_back(i),c[a[i]]=i;
	}
	dfs(n,-1);
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}
