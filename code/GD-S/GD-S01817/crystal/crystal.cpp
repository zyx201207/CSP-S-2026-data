#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for(cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N],sum[N],l,r,mid,pos,ans;
inline bool check(int x) {return a[x]*(x-mid+1)-(sum[x]-sum[mid-1]) <= m;}
start_code
openfile(crystal);
fastio();
cin>>n>>m;
for (int i = 1;i <= n;i ++) cin>>a[i];
sort(a+1,a+n+1);
for (int i = 1;i <= n;i ++) sum[i] = sum[i-1]+a[i];
for (int i = 1;i <= n;i ++)
{
	l = 1,r = pos = i;
	while (l <= r)
	{
		mid = l+r>>1;
		if (check(i)) r = mid-1,pos = min(pos,mid);
		else l = mid+1;
	}
	ans = max(ans,i-pos+1);
}
cout<<ans;
stop_code
