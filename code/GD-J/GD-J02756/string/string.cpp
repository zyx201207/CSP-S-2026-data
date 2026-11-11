#include <bits/stdc++.h> 
using namespace std;
long long n,ans;
vector<pair<long long,long long>>s;
bool clt(long long l,long long r)
{
	if(s[l].second<s[r].second)
	{
		s[r]={s[r].first,s[r].second-s[l].second};
		return false;
	}
	else 
	{
		s[l]={s[l].first,s[l].second-s[r].second};
		return true;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x,y;
		char t;
		cin>>x>>t;
		y=t-'a';
		pair<long long,long long> a={y,x};
		s.push_back(a);
	}
	long long l=0,r=n-1;
	while(l<r)
	{
		if(s[l].first==s[r].first)
		{
			if(s[l].second==s[r].second)l++,r--;
			else 
			{
				if(clt(l,r))r--;
				else l++;
			}
		}
		else
		{
			if(s[l].second==s[r].second)ans+=s[l].second,l++,r--;
			else 
			{
				if(clt(l,r))ans+=s[r].second,r--;
				else ans+=s[l].second,l++;
			}
		} 
	}
	cout<<ans; 
	return 0;
}
