#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,m,ans=0;
int a[N+5],vis[N+5];
void dfs(int x,int num,int cnt){
	if(vis[x]) return ;
	if(num==m){
		ans=max(ans,cnt);
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,num+1,(cnt&a[i]));
	vis[x]=0;
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n>2000){
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n;i++) dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}
