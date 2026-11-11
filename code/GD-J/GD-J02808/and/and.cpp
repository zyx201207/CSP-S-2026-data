#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000001],ans;
void maxn(long long hao,long long zhi,long long wei)
{
	if(wei==m)
	{
		ans=max(zhi,ans);
		return ;
	}
	if(hao>n)
	{
		return ;
	}
	if(wei==0)
	{
		for(int i=hao;i<=n;i++)
		{
			maxn(i+1,a[i],1);
		}
	}
	else
	{
		for(int i=hao;i<=n;i++)
		{
			if(a[i]&zhi>=ans)
			{
				maxn(i+1,a[i]&zhi,wei+1);
			}
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2*1e5)
	{
		maxn(1,0,0);
	}
	else
	{
		ans=a[n];
		for(int i=2;i<=m;i++)
		{
			ans&=a[1+n-i];
		}
	}
	cout<<ans;
	return 0;
 } 
