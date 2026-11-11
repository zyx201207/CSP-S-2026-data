#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,a[N],m,ans;
void dfs(int p,int s,int d)
{
	if(d>=m)
	{
		ans=max(ans,s);
		return;
	}
	if(p>n)return;
	int t=s;
	if(s==-1)s=a[p];
	dfs(p+1,s&a[p],d+1);
	s=t;
	if(m-d<=n-p)
	  dfs(p+1,s,d);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,-1,0);
	cout<<ans;
	return 0;
}
