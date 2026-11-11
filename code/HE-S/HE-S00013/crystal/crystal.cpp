#include <bits/stdc++.h>
using namespace std;

long long a[500010];
int main () {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long z = m;
    int ret = 1;
    for(int i = 1;i <= n;i++)
    {
        z = m;
        int cnt = 1;
        int l=i-1;
        while(z>=a[i]-a[l]&&l>=1)
        {
            int s = a[i]-a[l];
            z-=s;
            l--;
            cnt++;
        }
        ret = max(ret,cnt);
    }
    printf("%d",ret);
    return 0;
}
