#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int b;
	if(m==1)
	{
		cout<<a[1];
		return 0;
	} 
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				b=a[i]&a[i+1];
				ans=max(ans,b);
			}
		}
		cout<<ans;
	} 
	else
	{
		for(int i=1;i<m;i++)
		{
			b=a[i]&a[i+1];
			ans=b;
		}
		cout<<ans;
	}
}
