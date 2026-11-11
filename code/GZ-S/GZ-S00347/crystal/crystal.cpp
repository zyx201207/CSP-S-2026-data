//GZ-S00347 贵阳市观山湖区普瑞学校 吴林沂

#include <iostream>
using namespace std;


int main()
{
	freopen ("crystal.in",stdin);
	freopen ("crystal.out",stdout);

	long long a[10000],m,n;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	for(long long  i=n;i>=1;i--)
	{
		double sum=0;
		for(long long j=1;j<=i;j++)
		{
			sum+=a[j];
		}
		double mo=(sum+m)/i;
		long long mo2=(sum+m)/i;
		if(mo==mo2)
		{
			cout<<i-1;
			return 0;
		}
	}

	return 0;
}
