#include <bits/stdc++.h>
using namespace std;
long long d[200005];
int tong[50];
int n,m;
long long ans;
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if (a.first!=b.first)
		return a.first>b.first;
	return a.second>b.second;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&d[i]);
		int cs=0;
		while (d[i])
		{
			if (d[i]%2)
				tong[cs]++;
			d[i]/=2;
			cs++;
		}
	}
	vector <pair<int,int> > d;
	for (int i=0;i<50;i++)
	{
		if (tong[i]!=0)
			d.push_back({tong[i],i});
	}
	vector <int> c;
	sort(d.begin(),d.end(),cmp);
	for (int i=0;i<(int)d.size();i++)
	{
		if (d[i].first>=m)
			c.push_back(d[i].second);
		else
			break;
	}
	sort(c.begin(),c.end(),greater<int> {});
	if ((int)c.size()<m)
		printf("0");
	else
	{
		for (int i=0;i<min(m,(int)c.size());i++)
			ans+=(long long)pow(2,c[i]);
		printf("%lld",ans);
	}
	return 0;
}
