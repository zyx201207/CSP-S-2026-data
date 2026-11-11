#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=2e5+10;

int n,m;
int a[MAXN];
int cnt,maxn;
int ans;

inline bool cmp(int A,int B)
{
	return A>B;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	stable_sort(a+1,a+n+1,cmp);
	for(int i=31;i>=0;--i)
	{
		int now=(1ll<<i);
		cnt=maxn=0;
		for(int j=1;j<=n;++j)
		{
			if(a[j]&now)
			{
				++cnt;
				if(cnt==1) maxn=a[j];
				else maxn&=a[j];
			}
			if(cnt==m) break;
		}
		if(cnt==m) ans=max(ans,maxn);
	}
	cout<<ans;
	return 0;
}