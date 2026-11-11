#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e5+10;
int n,m,ans;
int a[maxn],b[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=__lg(i);j>=0;j--)
		{
			int v=res+(1<<j);
			if(v<=i&&v*a[i]-(b[i]-b[i-v])<=m) res=v;
		}
		ans=max(ans,res);
	}
	cout<<ans;
}
