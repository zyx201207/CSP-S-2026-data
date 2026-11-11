//GZ-S00347 贵阳市观山湖区普瑞学校 吴林沂
#include <iostream>
using namespace std;
int main()
{
	freopen("hub.in",stdin);
	freopen("hub.out",stdout);
	long long c,t;
	cin>>c>>t;
	long long n[10000],k[10000];
	for(long long i=1;i<=t;i++)
	{
		cin>>n[i];
		cin>>k[i];
	}
	long long u[10000],v[100000];
	long long max=0,sum=0;
	for(long long j=1;j<=t;j++)
	{
		for(long long i=1;i<=n[j]-1;i++)
		{
			cin>>u[i]>>v[i];
			if(v[i]-u[i]>max)
			{
				max=v[i]-u[i];
				sum++;
			}

		}
	}

	cout<<max<<endl<<sum+1;
	return 0;
}
