#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6;
pair<int,char>q[N],h[N],a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
		l+=a[i].first;
	}
	int half=(l+1)/2,s=0;
	int qs=0,hs=0;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i].first<=half)q[++qs]=a[i];
		else if(s<=half)
		{
			int p=half-s;
			if(l%2==1)p--; 
			if(p>=1)q[++qs]={p,a[i].second};
			if(l%2==1)p++;
			int o=a[i].first-p;
			if(o>=1)h[++hs]={o,a[i].second};
		}
		else
		{
			h[++hs]=a[i];
		}
		s+=a[i].first;
	}
	deque<pair<int,char>>qq,qh;
	int ans=0;
	for(int i=1;i<=qs;i++)qq.push_back(q[i]);
	for(int i=1;i<=hs;i++)qh.push_front(h[i]);
	while(!qq.empty()&&!qh.empty())
	{
		pair<int,char>x=qq.front(),y=qh.front();
		qq.pop_front();
		qh.pop_front();
		if(x.first==y.first&&x.second==y.second)continue;
		if(x.second==y.second)
		{
			if(x.first>y.first)
			{
				x.first-=y.first;
				qq.push_front(x);
			}
			else
			{
				y.first-=x.first;
				qh.push_front(y);
			}
		}
		else
		{
			if(x.first==y.first)
			{
				ans+=x.first;
				continue;
			}
			int cost=min(x.first,y.first);
			ans+=cost;
			if(x.first>y.first)
			{
				pair<int,char>ne;
				ne.second=x.second;
				ne.first=abs(x.first-y.first);
				qq.push_front(ne);
			}
			else
			{
				pair<int,char>ne;
				ne.second=y.second;
				ne.first=abs(y.first-x.first);
				qq.push_front(ne);
			}
		}
	}
	cout<<ans;
}
