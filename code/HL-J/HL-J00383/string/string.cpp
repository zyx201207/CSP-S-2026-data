#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll s=0,ss=0,b1=0,c1=0,ans=0;
	vector<pair<char,ll>>a,b,c;
	stack<pair<char,ll>>st; 
	for(int i=0;i<n;i++)
	{
		ll x;
		char y;
		cin>>x>>y;
		s+=x;
		a.push_back({y,x});
	}
	for(auto i:a)
	{
		if(ss>=s/2)
			st.push(i);
		else
		{
			if(ss+i.second>s/2)
			{
				if(s%2==1&&ss+i.second-1==s)
					b.push_back({i.first,i.second-1});
				else
				{
					b.push_back({i.first,s/2-ss});
					st.push({i.first,ss+i.second-s/2-s%2-1});
				}
			}
			else
				b.push_back(i);
			ss+=i.second;
		}
	}
	while(!st.empty())
	{
		c.push_back(st.top());
		st.pop();
	}
	while(s>1&&b1<b.size()&&c1<c.size())
	{
		if(b[b1].first!=c[c1].first)
			ans+=min(b[b1].second,c[c1].second);
		if(b[b1].second>c[c1].second)
		{
			s-=c[c1].second*2;
			b[b1].second-=c[c1].second;
			c1++;
		}
		else if(b[b1].second<c[c1].second)
		{
			s-=b[b1].second*2;
			c[c1].second-=b[b1].second;
			b1++;
		}
		else
		{
			s-=b[b1].second*2;
			b1++;
			c1++;
		}
	} 
	cout<<ans<<'\n';
	return 0;
}
