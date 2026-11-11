#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+55;
struct node
{
	int val;
	int ha[35];
}a[N];
int n,m;
int got[35];
bool cmp(node a,node b)
{
	return a.val < b.val;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].val;
		int w = a[i].val,now = 1;
		while(w)
		{
			if(w & 1)
			{
				a[i].ha[now] = 1;
			}
			now ++;
			w >>= 1;
		}
	}
	for(int i = 1;i<=31;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			got[i] += a[j].ha[i];
		}
	}
	int cnt = 0;
	map<int,int> mp;
	sort(a + 1,a + n + 1,cmp);
	for(int i = 31;i >= 1;i--)
	{
		if(got[i] < m)
		{
			continue;
		}
		map<int,int> mp2;
		for(int j = 1;j<=n;j++)
		{
			if(a[j].ha[i] &&!mp[j])
			{
				mp2[j] = 1;
				cnt ++;
			}			
		}
		for(int j = 1;j<=n;j++)
		{
			if(cnt > m && mp2[j])
			{
				mp2[j] = 0;
				cnt --;
			}
		}
		for(int j = 1;j<=n;j++)
		{
			if(mp2[j])
			{
				mp[j] = 1;
			}
		}
		if(cnt == m)
		{
			break;
		}
	}
	bool flag = false;
	int ans = 0;
	for(int i = n;i>=1;i--)
	{
		if(mp[i] && !flag)
		{
			ans = a[i].val;
		}
		else if(mp[i])
		{
			ans &= a[i].val;
		}
	}
	cout<<ans<<endl;
	return 0;
}










