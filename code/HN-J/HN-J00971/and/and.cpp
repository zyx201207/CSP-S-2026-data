#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
map<int,int> mp;
vector<int> g[N];
int check(int mid,int u)
{
	int res=(1<<u+1)-1,cnt=0;
	for(int i=0;i<g[u].size();i++)
		if((res&g[u][i])>=mid)
		{
			res&=g[u][i];
			cnt++;
		}
	return cnt>=m;
}
signed main()
{
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],cnt=0;
		while(x)
		{
			if(x%2==1)
			{
				mp[cnt]++;
				g[cnt].push_back(a[i]);
			}
			cnt++;
			x/=2;
		}
	}
	int id=0;
	for(int i=30;i>=1;i--)
	{
		if(mp[i]>=m)
		{
			id=i;
			break;
		}
	}
	if(id==0)
		cout<<0;
	else
	{
		int l=(1<<id),r=(1<<id+1)-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,id))
				l=mid+1;
			else
				r=mid-1;
		}
		cout<<r; 
	}
	return 0;
}
/*
0011
1111
1100
1100
4 2
3 15 12 12

5 3
31 3 1 15 7

*/ 
