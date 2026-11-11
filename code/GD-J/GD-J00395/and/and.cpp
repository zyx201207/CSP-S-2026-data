#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5;
const int V=30;
int n,m,b,ans;
vector<int>a,c;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b,a.push_back(b);
	for(int i=V;i>=0;i--)
	{
		c.clear();
		for(int now:a)
		{
			if((1<<i)&now) c.push_back(now);
		}
		if(c.size()>=m)
		{
			a.clear();
			for(int now:c) a.push_back(now);
		}
	}
	ans=a[0];
	for(int i=1;i<m;i++) ans=ans&a[i];
	cout<<ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;//cin>>_;
	while(_--) solve();
	return 0;
}// CSP2026-J/S RP++
