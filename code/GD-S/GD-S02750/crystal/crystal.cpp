#include <cstdio>
#include <vector>
using namespace std;
#define N 500005
long long s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max=0;
	scanf("%lld %lld",&n,&m);
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
	}
	for(long long i=0;i<n;i++)
	{
		long long t=m,g=0,c=0;
		vector<long long> arr;
		for(long long k=0;k<n;k++)
		{
			if(s[k]>s[i])
			{
				break;
			}
			if(t-(s[i]-s[k])>=0)
			{
				t-=s[i]-s[k];
				arr.push_back(s[k]),g++;
			}
			else
			{
				long long min_n=1e12+5,min_x=0;
				for(int j=c;j<arr.size();j++)
				{
					if(arr[j]<min_n)
					{
						min_n=arr[j],min_x=j;
					}
				}
				t+=s[i]-min_n;
				if(t+(s[i]-min_n)-(s[i]-s[k])>=0)
				{
					t=t+(s[i]-min_n)-(s[i]-s[k]);
					arr.push_back(s[k]);
					arr[min_x]=arr[c],arr[c]=min_n,c++;
				}
			}
		}
		max=g>max?g:max;
	}
	printf("%d",max);
	return 0;
}
