//GZ-J00456
//贵阳市白云区华师一学校 
//廖博亚 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e5+5;
ll a[N];
ll n,m;
ll Max=-2e9;
void dfs(ll x,ll num,ll res)
{
	if(num==m)
	{
		Max=max(Max,res);
		return ;
	}
	if(Max>res) return ;
	if(x>n) return ;
	if(num>0) dfs(x+1,num+1,res&a[x]);
	else dfs(x+1,num+1,a[x]);
	dfs(x+1,num,res);
}
bool cmp(ll x,ll y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	dfs(1,0,0);
	cout<<Max<<endl;
}
