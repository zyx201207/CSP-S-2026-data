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
const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],pos[M],cnt[M],ans[M];
bitset<M> f;
start_code
fastio();
openfile(card);
cin>>n>>m,a[n+1] = 0,pos[0] = n+1;
for (int i = 1;i <= n;i ++) cin>>a[i],cnt[a[i]] ++;
for (int i = n;i >= 1;i --) if (!pos[a[i]]) pos[a[i]] = i;
for (int i = 1;i <= m;i ++)
{
	f.reset();
	for (int j = pos[i];j <= n;j = pos[a[j+1]]) f.set(a[j]);
	for (int j = 1;j <= m;j ++) ans[j] += f[j]*cnt[i];
}
for (int i = 1;i <= m;i ++) cout<<ans[i]<<' ';
stop_code
