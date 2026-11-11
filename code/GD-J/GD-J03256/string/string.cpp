#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans;
char c[N];
vector<pair<int,char> > v;
pair<int,char> check(int s1,char c1,int s2,char c2)
{
	if(c1!=c2)
	{
		ans+=min(s1,s2);
		if(s1<s2)
		{
			return {abs(s1-s2),c2};
		}
		else
		{
			return {abs(s1-s2),c1};
		}
	}
	return {abs(s1-s2),c1};
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		v.push_back({a[i],c[i]});
	}
	int l=0,r=v.size()-1;
	while(l<=r)
	{
		pair<int,char> p=check(v[l].first,v[l].second,v[r].first,v[r].second);
		if(v[l].second==v[r].second)
		{
			if(p.first!=0)
			{
				if(v[l].first>v[r].first)
				{
					v[l].first=p.first;
					r--;
				}
				else
				{
					v[r].first=p.first;
					l++;
				}
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(p.first!=0)
			{
				if(p.second==v[l].second)
				{
					v[l].first=p.first;
					r--;
				}
				else
				{
					v[r].first=p.first;
					l++;
				}
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
