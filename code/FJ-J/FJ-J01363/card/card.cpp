#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e5+10;
ll n,m,a[N],ans[N];
bool b[N];
stack<ll> s;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++) b[j]=0;
		for (int j=i;j<=n;j++)
		{
			if (b[a[j]]==1)
			{
				while (s.top()!=a[j])
				{
					b[s.top()]=0;
					s.pop();
				}
			}
			else s.push(a[j]);
			b[a[j]]=1;
		}
		ll l=s.size();
		for (int j=1;j<=l;j++)
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}