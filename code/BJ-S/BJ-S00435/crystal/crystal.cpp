#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 1e12;

int n,m,a[N],cn[N],ans = 0;
map<int,int> mp;

bool check(int x){
    int cnt = 0;
    for (int i = 1;i <= n;i++){
        if (a[i] >= x) continue;
        if (cnt + x - a[i] > m) return false;
        cnt += x - a[i];
    }
    int nm = m,tot = 0;
    if (cnt <= m){
        for (int i = 1;i <= n;i++){
            if (a[i] > x) continue;
            if (nm >= x - a[i]){
                nm += x - a[i];
                tot++;
            }
        }
        ans = max(ans,tot);
        return true;
    }
    else return false;
}

bool cmp(int x,int y){ return x > y; }

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1,cmp);
    int l = -INF,r = INF;
    while(l <= r){
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld",ans);
    return 0;
}
