//褚哲宇 贵阳市第一中学 GZ-S00447 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long nothing,T;
	cin>>nothing>>T;
	for(long long p=0;p<T;++p)
	{
		long long n,d;
		long long ans=0;
		cin>>n>>d;
		if(d==1)
		{
			cout<<0;
			continue;
		}
		long long isl[n];
		for(long long i=0;i<n;++i)
		{
			cin>>isl[i];
		}	
		long long yue[n];
		for(long long i=0;i<n;++i)
		{
			yue[i]=0;
		}
		for(long long i=0;i<n;++i)
		{
			long long ji=isl[i]+d;
			if(i>0&&isl[i]-isl[i-1]>d)
			{
				break;
			}
			for(long long o=i+1;o<n;++o)
			{
				if(isl[o]<ji)
				{
					++yue[o];
				}
				else
				{
					if(o-1>i&&isl[o]-isl[i]!=d)
					{
						--yue[o-1];
					}
					break;
				}
			}
		}
		long long l,r;
		l=0;
		r=2;
		long long now=0;
		for( ;r<n;++r)
		{
			if(yue[r-1]==(d-1))
			{
				++now;
			}
			while(now==2)
			{
				++ans;
				++l;
				if(yue[l]==(d-1))
				{
					--now;
				}
			} 
		}
		cout<<ans<<endl;
	}
}
