#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long cnt=1e9,num=1;
		for(int i=1;i<n;i++)
		{
			long long sum=0,p=x[i];
			if(x[i+1]-x[i]>=d)
			{
				cout<<0<<endl;
				break;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-p>d)
				{
					sum++;
					p=x[j];
				}
			}
			if(sum<cnt)
			{
				cnt=sum;
				num=1;
			}
			else if(sum==cnt)
			{
				num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}