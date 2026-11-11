#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,m;
int a[21];
int v=(1<<30)-1,cnt=0;
int ans=0;
inline void dfs(int x){
	if(n-x+1+cnt<m)
		return;
	if(cnt>m)
		return;
	if(x==n+1){
		ans=max(ans,v);
		return;
	}
	dfs(x+1);
	int tmp=v;
	v&=a[x],cnt++,dfs(x+1),v=tmp,cnt--;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
