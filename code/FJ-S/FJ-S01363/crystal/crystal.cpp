#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mpi make_pair
#define fi first
#define se second
#define lb(x) (x&-x)
using namespace std;
const int maxn=5e5+10;
const int maxm=1e6+10;
const int INF=1e18;
const int mod=998244353;
int n,m,a[maxn],s[maxn],st[maxn][20];
inline int ask(int l,int r){int t=log2(r-l+1);return max(st[l][t],st[r-(1<<t)+1][t]);}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i],st[i][0]=a[i];
	for (int j=1;j<20;j++) for (int i=1;i+(1<<j)-1<=n;i++) st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int l=i,r=n,mid;
		while (l<r)
		{
			mid=l+r+1>>1;
			if (ask(i,mid)*(mid-i+1)-(s[mid]-s[i-1])<=m) l=mid;
			else r=mid-1;
		}
		ans=max(ans,l-i+1);
	}
	cout << ans;
	return 0;
}
