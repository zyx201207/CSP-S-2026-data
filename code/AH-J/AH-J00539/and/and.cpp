#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll n)
{
	ll sum=0;
	while(n!=0)
	{
		n/=2;sum++;
	}
	return sum;
}
vector<ll> ans;
ll maxn=-1;
void dfs(ll i,ll k,ll p)
{
	if(k==-1) {
		maxn=max(maxn,p);
		return ;
	}
	for(i;i<ans.size()-k;i++)
	{
		if(p==-1) dfs(i+1,k-1,ans[i]);
		else dfs(i+1,k-1,ans[i]&p);
	}
		

}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	ll n,m;cin>>n>>m;
	vector<ll>a(n+1);
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<vector<ll>> b(31);
	
	for(ll i=1;i<=n;i++)
	{
			b[qpow(a[i])].push_back(a[i]);
	}
	ll sum=0;
	for(ll i=30;i>=1;i--)
	{
		sum+=b[i].size();
		for(ll j=0;j<b[i].size();j++) ans.push_back(b[i][j]);
			if(sum>=m) break;
	}
	//for(ll i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	dfs(0,m-1,-1);
	cout<<maxn;
}