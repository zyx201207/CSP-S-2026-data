#include<bits/stdc++.h>
#define int long long
using namespace std;
const int S = 5e5+5;
int n,m,a[S],sst[S];

int func(int l,int r){
    l--;
    return sst[l] + a[r] * (r-l) - sst[r];
}

bool check(int x){
    for(int i = 1;i+x-1 <= n;i++){
        if(func(i,i+x-1) <= m) return 1;
    }
    return 0;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    // cout << a[n] << '\n';
    for(int i = 1;i <= n;i++){
        sst[i] = sst[i-1] + a[i];
        // f[i] = a[i] * i - sst[i];
        // if(f[i] > 9e18 || sst[i] > 9e18 || f[i] < -9e18 || sst[i] < -9e18) puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        // if(f[i] > m) {
        //     for(int j = i-10;j <= i;j++) cout << f[j] << ' ';puts("");
        //     for(int j = i-10;j <= i;j++) cout << sst[j] << ' ';puts("");
        //     // for(int j = i-10;j <= i;j++) cout << a[j] << ' ';puts("");
        //     // printf("%lld",i-1);
        //     // return 0;
        // }
    }

    int l = 0,r = n,ans = 1;
    while(l <= r){
        int mid = l+r >> 1;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    printf("%lld",ans);
    return 0;
}