#include <bits/stdc++.h>
using namespace std;
int n,m,tott[50];
int a[50][300010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);tott[31]=n;
	for(int i=1;i<=n;i++) scanf("%d",&a[31][i]);
	long long ans=0;
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=tott[i+1];j++)
		{
			if((a[i+1][j]&(1ll<<i)))
			{
				cnt++;
			}
		}
		if(cnt>=m) ans+=(1ll<<i);
		for(int j=1;j<=tott[i+1];j++)
		{
			if(cnt>=m)
			{
				if((a[i+1][j]&(1ll<<i)))
				{
					a[i][++tott[i]]=a[i+1][j];
				}
			}
			else a[i][++tott[i]]=a[i+1][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
