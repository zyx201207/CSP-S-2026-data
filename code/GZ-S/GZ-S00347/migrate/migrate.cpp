//GZ-S00347 贵阳市观山湖区普瑞学校 吴林沂
#include <iostream>
using namespace std;

long long n[1000],d[1000],x[1000];


long long xun(long long begin,long long end)
{
	long long sum=0,same=0;
	for(long long i=x[begin]+1;i<=x[end]+1;i++)
	{
		long long insum=10000;
		if(x[i]-x[begin]<=d[i])
		{
			insum+=x[i]-x[begin];
		}
		if(insum=sum)
		{
			same++;
		}
		if(insum<sum)
		{
			sum=insum;
		}
	}
	return same;
}
int main()
{

	//freopen("migrate.in",stdin);
	//freopen("migrate.out",stdout);
	long long c,t,x[10000];
	cin>>c>>t;
	for(long long i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(long long j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
	}
	for(long long i=1;i<=t;i++)
	{
		cout<<xun(c,t)<<endl;
	}

	return 0;

}
