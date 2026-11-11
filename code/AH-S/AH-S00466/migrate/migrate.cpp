//migrate.cpp,1s,1024MiB
#include<bits/stdc++.h>
using namespace std;
#define int long long
//i've got 192p!up to 250+...
int a[2000005],to[2000005];
vector<pair<int,int>>seg;
map<int,int>m;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--)
	{
		seg.clear();
		seg.push_back({-1,-1});
		m.clear();
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			to[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			if(to[i-1]==i)
				seg[seg.size()-1].second=to[i];
			else if(to[i]!=to[i-1])
			{
				seg.push_back({i,to[i]});
				m[i]=seg.size()-1;
			}
		}
		if(seg.size()==2)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<seg.size();i++)
		{
			int pos=m[seg[i].second-1];
			if(!pos)
				continue;
			ans+=(seg[i+1].first-seg[i].first)*(seg[pos].second-seg[pos-1].second);
		}
		cout<<ans<<'\n';
	}
}
