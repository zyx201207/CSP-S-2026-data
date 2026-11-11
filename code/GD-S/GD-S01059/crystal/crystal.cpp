#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=500010;
int n; ll m; ll	a[N], sum[N];
ll calc(int l,int r)
{
	ll cur=sum[r]-sum[l-1], tmp=1ll*a[r]*(r-l+1);
	return tmp-cur;	
} 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m; int ans=1;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1); for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1,j=1;i<=n;i++)
	{
		while (j<=n && calc(j,i)>m) j++;
		ans=max(ans,i-j+1);
	}
	cout << ans << "\n";
	
	return 0;
}
