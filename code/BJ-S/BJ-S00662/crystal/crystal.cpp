#include <bits/stdc++.h>

using namespace std;
long long n,m;
long long a[500005];
long long s;
long long ma;
long long h,en = 1;
bool cmp(long long x,long long y){
    return x > y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(long long i = 1;i <= n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    h++;
    s++;
    while(a[en]-a[h+1]<=m){
        m -= a[en]-a[++h];
        s++;
    }
    ma = max(ma,s);
    while(h < n){
        m += (a[en]-a[en+1])*(s-1);
        s--;
        en++;
        while(a[en]-a[h+1]<=m and h+1 <= n){
            m -= a[en]-a[++h];
            s++;
        }
        ma = max(ma,s);
    }
    printf("%lld",ma);

    return 0;
}
