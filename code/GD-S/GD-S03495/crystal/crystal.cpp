#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N=524288;
int n,m,a[N],ans=1;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	For(i,n) cin>>a[i];
	sort(a+1,a+n+1);
	
	int l=1,now=0;
	Fors(r,2,n)
	{
		now+=(r-l)*(a[r]-a[r-1]);
		while(l+1<=r and now>m)
		{
			now-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	
	return 0;
}
