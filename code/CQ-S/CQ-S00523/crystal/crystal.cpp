#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], sum[500005];
bool chk(int x){
    for(int i=x; i<=n; i++){
        if(a[i]*x-(sum[i]-sum[i-x])<=m)return 1;
    }return 0;
}
signed main(){
    freopen("crystal.in", "r", stdin);  
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;for(int i=1; i<=n; i++)cin >> a[i];
    sort(a+1, a+1+n);for(int i=1; i<=n; i++)sum[i]=sum[i-1]+a[i];
    int l=1, r=n, bt=1;
    while(l<=r){
        int md=(l+r)/2;
        if(chk(md))bt=md, l=md+1;
        else r=md-1;
    }cout << bt;
    return 0;
}