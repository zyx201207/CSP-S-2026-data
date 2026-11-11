#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
vector<int>v;
void solve(vector<int>v,int y)
{
	for(int i=y-1;i>=0;i--)
	{
		int cnt=0;
		for(auto it:v)
		{
			if(it&(1<<i))cnt++;
			//if(i==29&&it&(1<<i))cout<<i<<' ';
		}
		if(cnt>=m)
		{
			ans+=(1<<i);
			//cout<<i<<' ';
			vector<int>vv;
			for(auto it:v)
			{
				if(it&(1<<i))vv.push_back(it);
			}
			solve(vv,i);
			return;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	//cout<<n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
		//cout<<x;
	}
	solve(v,30);
	cout<<ans;
	return 0;
}
/*
4 2
2 3 15 12 12
5 3
31 3 1 15 7
*/
