#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
vector<int> val[N];
set<int> s;
int n,m,mx=-1,ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 ios::sync_with_stdio;
	 cin.tie(0);
	 cout.tie(0);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	int x=a[i];
		for(int j=0;x;j++,x>>=1)		
			if(x&1)
				val[j].push_back(i);			
	}
	for(int i=31;i>=0;i--)
	{
		if(val[i].size()>=m)
		{
			for(auto j:val[i])
				s.insert(j);
			mx=i;
			break;
		}
	}
	ans+=(1<<mx);
	for(int i=mx-1;i>=0;i--)
	{
		int diff,cnt=0;
		set<int> nw;
		for(int j:val[i])
		{
			if(s.find(j)!=s.end())
			{
				cnt++;
				nw.insert(j);
			}
		}
		if(cnt>=m)
		{
			s=nw;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

