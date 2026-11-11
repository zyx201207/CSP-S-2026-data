//GZ-S00347 贵阳市观山湖区普瑞学校 吴林沂

#include <iostream>
using namespace std;

long long ki[1000],at[1000][10],n;


long long xun(long long begin)
{
	for(long long o=1;o<=n;o++)
	{

	 for(long long i=1;i<=ki[o]*n;i++)
	 {

			if(at[i][1]==begin)
			return at[i][2];

	 }
 }
}


int main()
{

	freopen("subway.in",stdin);
	freopen("subway.out",stdout);
	long long c,m,d,q,w[10000];
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>ki[i];
		for(long long j=1;j<=ki[i];j++)
		{
			cin>>at[j][1]>>at[j][2];
		}
	}
	long long xy[10000][10];
	for(long long i=1;i<=q;i++)
	{
		cin>>xy[i][1];
		cin>>xy[i][2];
	}

	for(long long i=1;i<=q;i++)
	{
		long long sum=w[xy[i][1]]+w[xy[i][2]];
		for(long long i=xy[i][1];i<=xy[i][2];i++)
		{
			sum+=xun(i);
		}
		cout<<sum<<endl;
	}
	return 0;
}
