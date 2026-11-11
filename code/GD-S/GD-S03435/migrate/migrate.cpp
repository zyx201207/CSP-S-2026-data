#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+5;
int c,t,tot[maxn],path[maxn],num[maxn];
ll x[maxn];
void solve()
{
	int n;
	ll d,ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=2;i<=n;i++)
	{
		int l=i-1,r=i-1;
		for(int j=i;j>=1;j--) tot[j]=0,path[j]=0,num[j]=0;
		while(l>=1&&x[i]-x[l]<=d) tot[1]++,path[l]=1,num[l]=1,l--;
		for(;l>=1;l--)
		{
			while(x[r]-x[l]>d) tot[path[r]]-=num[r],r--;
			path[l]=path[r]+1;
			tot[path[l]]+=tot[path[r]];
			num[l]=tot[path[r]];
			if(tot[path[r]]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
