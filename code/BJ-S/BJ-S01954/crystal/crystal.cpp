#include<bits/stdc++.h>
using namespace std;
#define my ios::sync_with_stdio(0)

long long n, m, a[500005], ans, tot;

bool sim(long long x){
    long long cnt = 0;
    for(long long i = 1LL;i <= n;i++){
        if(x >= a[i]){
            cnt += (x - a[i]);
        }
    }
    return cnt <= m;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    my;
    cin.tie(0);
    cin >> n >> m;
    for(long long i = 1LL;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long l = -2e18, r = 2e18;
    while(l <= r){
        long long mid = (l + r) / 2;
        if(sim(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] <= ans){
            tot++;
        }
    }
    cout << tot;
    return 0;
}
