#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn],ans;
bool vis[maxn];
void f(int step,int add)
{
	if(step==m)
	{
		ans=max(ans,add);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=true;
		f(step++,add&a[i]);
		vis[i]=false;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	f(0,pow(2,30)-1);
	cout<<ans;
	return 0;
}
