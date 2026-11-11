#include<bits/stdc++.h>
using namespace std;
long long n,d,arr[2000005],ans;
int dfs(int s,long long cnt,int e)
{
	if(s == e)
	{
		if(s-cnt==1 || s>e) return 0;
		return cnt;
	}
	if(dfs(s+1,cnt+1,e) == dfs(s+2,cnt+1,e) && dfs(s+1,cnt+1,e) != 0)
	{
		ans++;
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=4;i<=n;i++) dfs(1,0,i);
	cout<<ans<<endl;
}
int main()
{
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _=1,c;
	cin>>c>>_;
	while(_--) solve();
	return 0;
}

