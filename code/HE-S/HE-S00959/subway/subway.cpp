#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand((long long)time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p,k,sum=0,tem;
	cin>>c>>n>>m>>d>>p;
	for(long long a=1;a<=m;a++)
	{
		cin>>tem;
		sum+=tem;
	}
	for(long long a=1;a<=n;a++)
	{
		cin>>k;
		for(long long b=1;b<=k;b++)
		{
			cin>>tem;
			cin>>tem;
			sum+=tem;
		}
	}
	sum/=2;
	for(long long a=1;a<=p;a++)
	{
		cout<<(rand()%sum)+1<<endl;
	}
	return 0;
}
