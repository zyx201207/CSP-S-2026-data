#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[7000005];
bool cmp(int x,int y)
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
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
	{
		bool flag1=1;
		for(int j=1;j<i;j++)
		{
			if(m-abs(a[i]-a[j])+1)
			{
				m-=abs(a[i]-a[j]);
			}
			else
			{
				m-=abs(a[i]-a[j]);
				flag1=0;
				break;
			}
		}
		if(flag1)
		{
			for(int k=1;k<=i;k++)a[k]=a[i];
		}
		if(!m)break;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[1])ans++;
	}
	cout<<ans;
	return 0;
}
