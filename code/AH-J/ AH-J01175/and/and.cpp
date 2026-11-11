#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans[200010],k=1,x;
bool pd[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans[0]=1;
	for(int i=1;i<=30;i++)
	{
		ans[0]+=2*k;
		k*=2;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((ans[i]<(ans[i-1]&a[j]))&&pd[j]==0)
			{
				ans[i]=ans[i-1]&a[j];
				x=j;
			}
		}
		pd[x]=1;
	}
	cout<<ans[m];
	return 0;
}
