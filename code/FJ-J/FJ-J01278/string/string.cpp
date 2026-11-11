#include<bits/stdc++.h>
using namespace std;
deque<pair<long long,int> > p; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long s;
		char c;
		cin>>s>>c;
		if(!p.empty() && p.back().second==c)
			p.back().first+=s;
		else
			p.push_back({s,c});
	} 	
	while(!p.empty())
	{
		if(p.size()<2)
			break;
		long long s1=p.front().first;
		char c1=p.front().second;
		long long s2=p.back().first;
		char c2=p.back().second;
		p.pop_back();
		p.pop_front();
		if(s1>s2)
		{
			p.push_front({s1-s2,c1});
			if(c1!=c2)
				ans+=s2;
		}
		if(s2>s1)
		{
			p.push_back({s2-s1,c2});
			if(c1!=c2)
				ans+=s1;
		}
		if(c1!=c2 && s1==s2)
			ans+=s1;
	}
	cout<<ans<<endl; 
	return 0;
}

