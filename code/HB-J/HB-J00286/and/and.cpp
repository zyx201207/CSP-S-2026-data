#include<bits/stdc++.h>
using namespace std;
int maxn=0;
int a[200005],ans;
int main()
{
	freopen("and.in","stdin","r");
	freopen("and.out","stdout","w");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn<<endl;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else
	{
		cout<<n-m<<endl;
		return 0;
	}
	return 0;
}
