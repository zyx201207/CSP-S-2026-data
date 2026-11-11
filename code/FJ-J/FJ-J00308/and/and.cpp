#include <bits/stdc++.h>
using namespace std;

int n,m,mx,mn;
int a[200005];
int ans = -1;
void dfs(int i,int cnt,int k)
{
	if(k==m)
	{
		ans=max(cnt,ans);
		return ;
	}
	if(i>n)return ;
	if(n-i+1+k==m)
	{
		dfs(i+1,cnt&a[i],k+1);
		return ;
	}
	dfs(i+1,cnt&a[i],k+1);
	dfs(i+1,cnt,k);
	return ;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int tot1=0,tot2=0,tot3=0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		mn=min(a[i],mn);
		tot1+=(a[i]==1);
		tot2+=(a[i]==1);
		tot3+=(a[i]==1);
	}
	if (tot1+tot2+tot3==n)
	{
		if(tot3>=m)ans=3;
		else if(tot3+tot2>=m)ans=2;
		else if(tot3+tot1>=m)ans=1;
		else ans = 0;
	}
	else if(n>1e5&&m!=n-1)ans=mn;
	else
	{
		dfs(1,pow(2,21)-1,0);
	}
	cout<<ans;
	return 0;
}
