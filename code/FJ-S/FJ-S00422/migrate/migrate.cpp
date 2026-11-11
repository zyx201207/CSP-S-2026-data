#include<iostream>
using namespace std;
long long hhc,t;
long long n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>hhc>>t;
	while(t--)
	{
		cin>>n>>d;
		long long a[100000],b[1000000],zong=0;
		for(int z=1;z<=n;z++)
		{
			cin>>a[z];
		}
		long long cha=a[2]-a[1];
		long long i=d/cha;
		for(int z=1;z<i;z++)
		{
			long long j=i+z;
			for(int y=j;y<=n&&y<2*i;y++)
			{
				b[y]++;
			}
		}
		for(int z=1;z<=n;z++)
		{
			zong+=b[z];
		}
		cout<<zong<<endl;
	}

	return 0;
}
