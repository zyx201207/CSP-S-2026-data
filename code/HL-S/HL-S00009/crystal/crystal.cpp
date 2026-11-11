#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],sum[500010],tes,num=1,ans,vis=1;
int cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=vis;j<=i-1;j++)
		{
			sum[j]=a[i]-a[j];
		}
		sort(sum+1,sum+i-vis+1,cmp);
		for(int j=1;j<=i-vis;j++)
		{
			if(tes+sum[j]<=m)
			{
				tes=tes+sum[j];
				num++;
			}
			else
			{
				break;
				vis=i-j+2;
			}
				
		}
		ans=max(ans,num);
		num=1;
		tes=0;
		for(int j=1;j<=i-vis;j++)
			sum[j]=0;
	}
	cout<<ans;
	return 0;
} 
