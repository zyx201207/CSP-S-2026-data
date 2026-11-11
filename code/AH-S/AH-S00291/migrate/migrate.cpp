#include<bits/stdc++.h>
using namespace std;
long long a[2000005],c,t,n,m,s,x,y;
void shuangsheng()
{
	for(int i=x+3;i<=y;i++)
	{
		if(a[i]-a[i-1]<=m&&a[i]-a[i-2]<=m&&a[i-1]-a[i-3]<=m&&a[i-2]-a[i-3]<m&&a[i]-a[i-3]>m)
		{
			s++;
			for(int j=i+1;j<=y;j++)
			{
				if(a[j]-a[j-2]>m&&a[j]-a[j-1]<m)
				{
					s++;
				}
				else
				{
					break;
				}
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		s=0;
		x=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			if(a[i]-a[i-1]>m||i==n)
			{
				y=i;
				if(y-x+1>=4)
				{
					shuangsheng();
				}
				x=i;
			}
		}
		cout<<s<<endl;
	}
}
