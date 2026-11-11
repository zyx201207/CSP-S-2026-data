#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005
int a[MAXN];
int sum[MAXN];
int n,m;
bool judge(int mid){
    for(int i = 1; i + mid - 1 <= n; i++){
        int l = i,r = i + mid - 1;
        if(a[r] * mid - (sum[r] - sum[l-1]) <= m) return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    int l = 1,r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(judge(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n",r);
    return 0;
}