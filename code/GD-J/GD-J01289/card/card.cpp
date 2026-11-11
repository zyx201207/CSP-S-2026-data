#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll N=5e5+10,M=3e5+10;
ll n,m,a[N],id[M],ans[M];//id[i]表示点数为i的卡牌最后一次出现的位置 

void solve()
{
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i],id[a[i]]=i;
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i;j<=n;)
		{
			ans[a[j]]++;
			j=id[a[j]]+1;
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
