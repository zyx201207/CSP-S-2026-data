#include<iostream>
#include<list>
using namespace std;
int n,m;
long long ans;
list<long long>l;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		long long a;
		scanf("%lld",&a);
		l.push_back(a);
	}
	for(int i=30;i>=0;i--)
	{
		int cnt=0;
		for(int x:l)
		{
			if((x>>i)&1)
				cnt++;
		}
		if(cnt<m)
			continue;
		for(auto it=l.begin();it!=l.end();)
		{
			if(!(((*it)>>i)&1))
				it=l.erase(it);
			else
				it++;
		}
	}
	auto it=l.begin();
	ans=*it;
	for(int i=1;i<=m;i++)
	{
		ans&=*it;
		it++;
	}
	printf("%lld",ans);
	return 0;
}
