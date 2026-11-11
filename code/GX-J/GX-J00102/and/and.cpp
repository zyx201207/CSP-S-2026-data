#include <bits/stdc++.h>

using namespace std;
long long n,m,a[200100],ans = 0;
void jisuan(long long x,long long y,long long z){
     if(y == m){
        ans = max(ans,x);
        return;
     }
     if(n - z + y + 1 < m){
        return;
     }
     for(int i = z,q = 1;q <= m-y+1;i++,q++){
         jisuan(x&a[i],y+1,i+1);
     }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i = 1;i <= n;i++){
    jisuan(a[i],1,i+1);
    }
    cout << ans;
    return 0;
}
