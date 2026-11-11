#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for (cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
//#define int long long
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans;
bitset<N> f;
start_code
fastio();
openfile(and);
cin>>n>>m,f.set();
for (int i = 1;i <= n;i ++) cin>>a[i];
for (int i = 30,cnt;i >= 0;i --)
{
	cnt = 0;
	for (int j = 1;j <= n;j ++) if (f[j] && ((a[j]>>i)&1)) cnt ++;
	if (cnt >= m)
	{
		ans |= 1<<i;
		for (int j = 1;j <= n;j ++) if (f[j] && !((a[j]>>i)&1)) f.reset(j);
	}
}
cout<<ans;
stop_code
