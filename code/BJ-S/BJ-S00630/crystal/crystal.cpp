#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5+5;
constexpr int M = 1e18;
constexpr int INF = 1e12+1;

int n, m;
int a[N];
int b[N];
int compute(int x, int k){
    return k*a[x]-b[x]+b[x-k];
}
bool check(int k){
    for(int i=k;i<=n;i++){
        if(compute(i, k)<=m) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++) b[i] = b[i-1]+a[i];
    int l = 1, r = n;
    while(l<r){
        int mid = l+((r-l)>>1);
        if(check(mid)){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    cout<<l-1;
    return 0;
}
