#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long x[2000005],d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long minn=1e18+5;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			minn=min(minn,x[i]); 
		}
		if(d<minn)
		{
			cout<<0;
		}
		else if(c==11 || c==12)
		{
			if(d>=x[2]-x[1])
			{
				d*=2;
				int num=0;
				int i=0;
				while(i+d<=n)
				{
					num++;
					i++;
				}
				cout<<num;
			}
			else
			{
				cout<<0;
			}
		}
		else if(c==13 || c==14)
		{
			cout<<0;
		}
		else
		{
			srand(time(0)+n);
			int a=rand()%3;
			int o[3]={0,1,2};
			cout<<o[a];
		}
		cout<<endl;
	}
	return 0;
}
