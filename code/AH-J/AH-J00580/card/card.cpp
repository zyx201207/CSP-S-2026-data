#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],f[N],fa[N],Tong[M],lst[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=n;i;i--)
	{
		if(!Tong[a[i]]) lst[a[i]]=i,fa[i]=i+1;
		else fa[i]=Tong[a[i]];
		Tong[a[i]]=i;
	}
	for(ll i=1;i<=n;i++) f[fa[i]]+=(++f[i]);
	for(ll i=1;i<=m;i++) cout<<f[lst[i]]<<" ";
}
