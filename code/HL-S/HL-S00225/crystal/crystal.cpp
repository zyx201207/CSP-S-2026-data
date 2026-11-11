#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,l,r,ans = 1,s;
bool check(long long x){
    long long cnt = 0;
    for(int i = 1;i <= x;i++){
        cnt += a[x] - a[i];
    }return cnt <= m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        //cin >> a[i];
        if(a[i] < 0) s++;
    }sort(a+1,a+n+1);
    l = 1,r = n;
    while(l < r){
        long long mid = (l+r)/2;
        if(check(mid)){
            ans = max(ans,mid);
            l = mid+1;
        }else{
            r = mid-1;
        }
    }cout << ans << '\n';
    return 0;
}
