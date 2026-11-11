#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const long long N = 2e5+10;
vector<pair<long long ,char> > ls;
vector<pair<long long ,char> > us;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ls.push_back({0,0});
	long long n,sum = 0;
	scanf("%lld",&n);
	for(long long i=0;i<n;i++)
	{
		long long a;
		char c;
		scanf("\n%lld %c",&a,&c);
		if(ls.size()==1||ls.back().second!=c)
		{
			ls.push_back({a,c});
		}
		else
		{
			ls.back().first += a;
		}
		sum+=a;
	}
	long long half = (sum+1)/2,sm = 0;
	bool f = 0;
	for(long long i=1;i<ls.size();i++)
	{
		long long nsm = sm + ls[i].first;
		if(nsm==half&&sum%2)
		{
			if(ls[i].first-1>0)
			us.push_back({ls[i].first-1,ls[i].second});
			f = 1;
		}
		if(!f&&nsm>half)
		{
			if(sum%2)
			{
				if(half-sm-1>0)
				us.push_back({half-sm-1,ls[i].second});
				if(nsm-half>0)
				us.push_back({nsm-half,ls[i].second});
			}
			else
			{
				if(half-sm>0)
				us.push_back({half-sm,ls[i].second});
				if(nsm-half>0)
				us.push_back({nsm-half,ls[i].second});
			}
			f = 1;
		}
		else
		{
			us.push_back(ls[i]);	
		}
		sm=nsm;
	}
	long long ans = 0;
	long long lsum = 0,rsum = 0;
	for(long long i=0,j = us.size()-1;i<j;)
	{
		while(us[i].first==0) i++;
		while(us[j].first==0) j--;
		if(us[i].second != us[j].second)
		{
			if(us[i].first<us[j].first)
			{
				ans+=us[i].first;
				us[j].first-=us[i].first,i++;
			}
			else if(us[i].first == us[j].first)
			{
				ans+=us[i].first,i++,j--;
			}
			else
			{
				ans+=us[j].first;
				us[i].first-=us[j].first,j--;
			}
		}
		else
		{
			if(us[i].first<us[j].first)
			{
				us[j].first-=us[i].first,i++;
			}
			else if(us[i].first == us[j].first)
			{
				i++,j--;
			}
			else
			{
				us[i].first-=us[j].first,j--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
