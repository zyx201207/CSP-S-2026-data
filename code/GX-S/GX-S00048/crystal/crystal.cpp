#include <bits/stdc++.h>

using namespace std;
long long n,m,a[510000],b[510000],z = 0,ans = 0,t = 1,q = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(long long i = 1;i <= n;i++){
        z += (a[i] - a[i-1]) * (i-t);
        if(z > m){
            q = i - t;
            ans = max(ans,q);
            z -= a[i] - a[t];
            t++;
        }else if(z == m){
            q = i - t;
            ans = max(ans,q);
        }
    }
    printf("%lld",ans);
    return 0;
}
