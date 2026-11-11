#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

struct node
{
	ll a;
	char b;
};

ll n,ans,a[200005],lg1,lg2;
char b[200005];
vector<node> l1;
vector<node> l2;
bool flag=true;

inline ll abss(ll a)
{
	return (a<0?(-a):a);
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i=1;i<=n;++i)
	{
		cin >> a[i] >> b[i];
	}
	for(ll i=1;i<=(n/2)+(n%2);++i)
	{
		if(flag&&a[i]==a[n-i+1])
		{
			if(b[i]==b[n-i+1])
			{
				continue;
			}
			else
			{
				ans+=a[i];
			}
			if(!l1.empty())
			{
				ll cache=0;
				bool cachedir=false;
				char cachechar;
				for(;(!l1.empty())&&(!l2.empty());)
				{
					if(cache!=0)
					{
						if(!cachedir)
						{
							if(cachechar!=l2[0].b)
							{
								ans+=cache;
							}
							l2[0].a-=cache;
							cache=0;
							cachedir=false;
							cachechar=l1[0].b;
						}
						else
						{
							if(cachechar!=l1[0].b)
							{
								ans+=cache;
							}
							l1[0].a-=cache;
							cache=0;
							cachedir=true;
							cachechar=l2[0].b;
						}
					}
					cache+=abss(l1[0].a-l2[0].a);
					cachedir=l1[0].a<l2[0].a;
					if(!cachedir)
					{
						cachechar=l1[0].b;
					}
					else
					{
						cachechar=l2[0].b;
					}
					if(l1[0].b!=l2[0].b)
					{
						ans+=min(l1[0].a,l2[0].a);
					}
					vector<node>::iterator cci=l1.begin();
					vector<node>::iterator ccj=l2.begin();
					l1.erase(cci);
					l2.erase(ccj);
				}
				if(cache!=0)
				{
					ans+=cache;
				}
			}
		}
		else
		{
			flag=false;
			if(!l1.empty()&&b[i]==l1[l1.size()-1].b)
			{
				l1[l1.size()-1].a+=a[i];
			}
			else
			{
				l1.push_back({a[i],b[i]});
			}
			lg1+=a[i];
			if(!l2.empty()&&b[n-i+1]==l2[l2.size()-1].b)
			{
				l2[l2.size()-1].a+=a[n-i+1];
			}
			else
			{
				l2.push_back({a[n-i+1],b[n-i+1]});
			}
			lg2+=a[n-i+1];
			if(lg1==lg2)
			{
				lg1=0;
				lg2=0;
				flag=true;
			}
		}
	}
	if(!l1.empty())
	{
		ll cache=0;
		bool cachedir=false;
		char cachechar;
		for(;(!l1.empty())&&(!l2.empty());)
		{
			if(cache!=0)
			{
				if(!cachedir)
				{
					if(cachechar!=l2[0].b)
					{
						ans+=cache;
					}
					l2[0].a-=cache;
					cache=0;
					cachedir=false;
					cachechar=l1[0].b;
				}
				else
				{
					if(cachechar!=l1[0].b)
					{
						ans+=cache;
					}
					l1[0].a-=cache;
					cache=0;
					cachedir=true;
					cachechar=l2[0].b;
				}
			}
			cache+=abss(l1[0].a-l2[0].a);
			cachedir=l1[0].a<l2[0].a;
			if(!cachedir)
			{
				cachechar=l1[0].b;
			}
			else
			{
				cachechar=l2[0].b;
			}
			if(l1[0].b!=l2[0].b)
			{
				ans+=min(l1[0].a,l2[0].a);
			}
			vector<node>::iterator cci=l1.begin();
			vector<node>::iterator ccj=l2.begin();
			l1.erase(cci);
			l2.erase(ccj);
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

