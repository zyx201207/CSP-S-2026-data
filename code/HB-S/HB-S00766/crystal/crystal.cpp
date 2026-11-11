#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lx LONG_MAX
#define ln LONG_MIN
const int qq = 5e5+10;
ll n,m,a[qq];
ll s[qq];
ll l = 0,r = qq;

bool check(int x){
    for(int i = 0;i+x <= n;i ++){
        ll p = (s[i+x]-s[i]);
        p = a[i+x]*x-p;
        if(m >= p) return 1;
    }return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i ++){scanf("%lld",&a[i]);}
    sort(a+1,a+1+n);
    for(int i = n+1;i <= 5e5+5;i ++){a[i] = lx;}
    for(int i = 1;i <= n;i ++){s[i] = s[i-1]+a[i];}
    for(int i = n+1;i <= 5e5+5;i ++){s[i] = lx;}
    while(r > l){
        ll mid = (r+l)/2+1;
        if(check(mid)){
            l = mid;
        }else r = mid-1;
    }printf("%lld",r);
    return 0;
}
