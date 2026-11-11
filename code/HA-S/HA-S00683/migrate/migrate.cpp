#include <bits/stdc++.h>
using namespace std;
long long h,t,n,d,a[10000001],b[10000001],l,c[10000001];
int num,k,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>h>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		sum=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
			k=1;
			while((a[j+k]-a[j])<=d && (j+k)<=n)
			{
				b[j]++;
				k++;			}
		}
		
		for(int j=n;j>=4;j--)
		{
			num=0;
			for(int g=2;g<=(a[j]-a[1])/d+1;g++)
			{
				for(int g1=j-b[j-g];g1>=j-b[j-g-1];g1--)
				{
					num++;
				}
				if(num==2)
				{
					sum++;
				}
			}
			
		}
		cout<<sum<<endl;
	}
	return 0;
}

