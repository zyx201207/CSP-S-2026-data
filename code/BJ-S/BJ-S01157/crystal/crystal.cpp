
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int a[N],c[N],m,n;
bool last;
bool check(int x){
    if(x == 1)
        return 1;
    int sum = 0,minn = LLONG_MAX;
    for(int i=2;i<=x;i++)
        sum += (i-1)*c[i];
    minn = min(minn , sum);
    for(int i=x+1;i<=n;i++){
        sum -= a[i-1]-a[i-x];
        sum += c[i]*(x-1);
        minn = min(minn , sum);
    }
    if(minn <= m)
        return 1;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        c[i] = a[i]-a[i-1];
    int l = 1 , r = n , mid;
    while(l < r){
        mid = (l+r+1)/2;
        if(check(mid))
            l = mid;
        else
            r = mid-1;
    }
    cout<<l;
    return 0;
}
