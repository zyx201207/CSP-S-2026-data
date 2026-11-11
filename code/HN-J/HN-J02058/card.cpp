#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],p[500010],lst[500010],siz[500010];
vector<int>v[500010];
void dfs(int x){
	siz[x]=1;
	for(int i:v[x])dfs(i),siz[x]+=siz[i];
	return;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!p[a[i]]){
			p[a[i]]=lst[a[i]]=i;
			v[i+1].push_back(i);
		}else{
			v[lst[a[i]]].push_back(i);
			lst[a[i]]=i;
		}
	}
	dfs(n);
	for(int i=1;i<=m;i++)cout<<siz[p[i]]<<' ';
	return 0;
}

