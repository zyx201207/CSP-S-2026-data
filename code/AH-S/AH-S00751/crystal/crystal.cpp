#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n, m;
const int N = 5e+5+5;
int a[N], b[N], nn, sum[N], pre_s[N], cost[N];
// lst: we have to upd from lst[i] to i, that we can finish its x
// pre_s[i] - pre_s[lst-1] >= x
// pre_s[lst-1] <= pre_s[i]- x
// pre_s[lst] > pre_s[i] -x
// lst = lower_bound(pre_s+1, pre_s+i+1, pre_s[i] - x) - pre_s;
//


int id(int x){ return lower_bound(b+1,b+nn+1,x)-b; }
bool check(int x){
    // x equals
    for(int i = 1; i <= nn; i++)
        if(sum[i] >= x) return true;
    // for each b[i], upd b[1 ~ i-1] -> b[i];
    // sum[i] bis, x - sum[i] numbers,
    // so if sumof sum[1~i-1] < x-sum[i], continue;
    // how to upd?
    // greedily, b[i-1], b[i-2], ... ,b[1]
    // for b[j] the cost c = b[i]-b[j], if
    // and it
    for(int i = 1; i <= nn; i++){
        if(pre_s[i] < x) continue;
        int lst = upper_bound(pre_s+1, pre_s+i+1, pre_s[i] - x) - pre_s;
        int s = pre_s[i] - pre_s[lst-1];
        // upd [lst, i]
        // we only consider about its val,
        // cost (i-lst+1)*b[i] - sumof(j=[lst,i]) sum[j]*b[j]
        int c = 0;
        if(x == s) c = s*b[i] - (cost[i] - cost[lst-1]);
        else       c = (pre_s[i] - pre_s[lst]) * b[i] - (cost[i] -cost[lst])+
                       (x - pre_s[i] + pre_s[lst]) *  (b[i] - b[lst]);

        if(c <= m) return true;
    }
    return false;

}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];

    sort(b+1, b+n+1);
    nn = unique(b+1, b+n+1) - b -1;
    for(int i = 1; i <= n; i++) sum[id(a[i])] ++;
    for(int i = 1; i <= nn; i++) pre_s[i] = pre_s[i-1] + sum[i];
    for(int i = 1; i <= nn; i++) cost[i] = cost[i-1] + sum[i] * b[i];



    int L = 1, R = n, ans = 1;
    while(L <= R){
        int mid = (L+R>>1);
        if(check(mid)) ans = mid, L = mid+1;
        else R = mid-1;
    }
    cout << ans;
    return 0;
}
