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
#define int long long
using namespace std;
const int N = 2e5+5;
struct node {int x;char c;} v1[N],v2[N];
int n,a[N],ans,l,len1,len2;
char c[N];
inline int getlen(int i,int j) {return min(v1[i+1].x-1,v2[j+1].x-1)-max(v1[i].x,v2[j].x)+1;}
start_code
openfile(string);
cin>>n;
for (int i = 1;i <= n;i ++) cin>>a[i]>>c[i],a[i] += a[i-1];
l = a[n];
for (int i = 1;a[i-1]+1 <= l/2;i ++) v1[++len1] = {a[i-1]+1,c[i]};
for (int i = n;a[i] >= l-l/2+1;i --) v2[++len2] = {l-a[i]+1,c[i]};
v1[++len1] = {l/2+1,'!'},v2[++len2] = {l/2+1,'!'};
for (int p1 = 1,p2 = 1;p1<len1 && p2<len2;)
{
	if (v1[p1].c != v2[p2].c) ans += getlen(p1,p2);
	if (v1[p1+1].x > v2[p2+1].x) p2 ++;
	elif (v1[p1+1].x < v2[p2+1].x) p1 ++;
	else p1 ++,p2 ++;
}
cout<<ans;
stop_code
