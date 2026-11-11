#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans;
bool b[N];
void dfs(long long step,long long s)
{
	if(step>m)
	{
		ans=max(s,ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])continue;
		b[i]=1;
		dfs(step+1,s&a[i]);
		b[i]=0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=1;
		dfs(2,a[i]);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}
