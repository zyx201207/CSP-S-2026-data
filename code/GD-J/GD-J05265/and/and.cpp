#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m,a[N],ans=0;
vector<ll>v[35];
void solve(ll h)
{
	while(h>=0&&v[h].size()<m)h--;
	if(h<0)return;
	ans|=(1<<h);
	for(int i=0;i<h;i++)v[i].clear();
	for(int i=0;i<v[h].size();i++)
	{
		for(int j=0;j<h;j++)
		{
			if(v[h][i]&(1<<j))
				v[j].push_back(v[h][i]);
		}
	}
	solve(h-1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=30;j++)
		{
			if(a[i]&(1<<j))
			{
				v[j].push_back(a[i]);
			}
		}
	}
	solve(30);
	cout<<ans;
	return 0;
}

