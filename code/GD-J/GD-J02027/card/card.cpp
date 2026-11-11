#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],cnt[300005],cou[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<ll> que;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]>=1)
			{
				while(!que.empty()&&que.top()!=a[j])cnt[que.top()]--,que.pop();
				que.pop();
				cnt[a[j]]--;
			}
			cnt[a[j]]++;
			que.push(a[j]);
		}
		while(!que.empty())
		{
			cou[que.top()]++;
			que.pop();
		}
		for(int j=1;j<=m;j++)cnt[j]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cou[i]<<' ';
	}
	return 0;
}
