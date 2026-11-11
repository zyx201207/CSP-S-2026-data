#include<bits/stdc++.h>
#define int long long
using namespace std;
int n; 
deque<pair<int,char> >q;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int x;
		char c;
		cin>>x>>c;
		q.push_back({x,c});
	}
	int ans=0;
	while(q.size()>=2)
	{
		int x1=q.front().first;
		char c1=q.front().second;
		q.pop_front();
		int x2=q.back().first;
		char c2=q.back().second;
		q.pop_back();
		if(x1<x2)
		{
			if(c1!=c2)
				ans+=x1;
			q.push_back({x2-x1,c2});
		}
		else if(x2<x1)
		{
			if(c1!=c2)
				ans+=x2;
			q.push_front({x1-x2,c1});
		}
		else
		{
			if(c1!=c2)
				ans+=x1;
		}
	}
	cout<<ans;
	return 0;
}
