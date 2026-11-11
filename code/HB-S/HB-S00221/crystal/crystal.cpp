/*
crystal
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10, inf = 0x3f3f3f3f;

int n, ans;
ll m, a[N], sum[4 * N], tag[4 * N];

void up(int p){
    sum[p] = sum[2*p] + sum[2*p + 1];
}

void down(int p, int l, int r){
    int lc = 2 * p, rc = 2 * p + 1, mid = (l + r) >> 1;
    if(tag[p] == 0) return;
    tag[lc] += tag[p];
    sum[lc] += tag[p] * (mid - l + 1);
    tag[rc] += tag[p];
    sum[rc] += tag[p] * (r - mid);    
    tag[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, ll val){
    if(ql <= l && r <= qr){
        sum[p] += val * (r - l + 1);
        tag[p] += val;
        return;
    }
    down(p, l, r);
    int mid = (l + r) >> 1, lc = 2 * p, rc = 2 * p + 1;
    if(ql <= mid) update(lc, l, mid, ql, qr, val);
    if(qr > mid) update(rc, mid + 1, r, ql, qr, val);
    up(p);
}

ll query(int p, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return sum[p];
    down(p, l, r);
    int mid = (l + r) >> 1, lc = 2 * p, rc = 2 * p + 1;
    ll res = 0;
    if(ql <= mid) res += query(lc, l, mid, ql, qr);
    if(qr > mid) res += query(rc, mid + 1, r, ql, qr);
    return res;
}

int get(int p, int l, int r, int qr, ll val){
    if(l == r){
        if(sum[p] >= val) return l;
        else return qr;
    }
    down(p, l, r);
    int lc = 2 * p, rc = 2 * p + 1, mid = (l + r) >> 1;
    if(qr <= mid){
        return get(lc, l, mid, qr, val);
    }else{
        if(sum[lc] >= val){
            return get(lc, l, mid, qr, val);
        }else{
            return get(rc, mid + 1, r, qr, val - sum[lc]);
        }
    }
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    
    ans = 1;
    for(int i = 2; i <= n; i ++){
        update(1, 1, n, 1, i - 1, a[i] - a[i - 1]);
        ll sum_i = query(1, 1, n, 1, i);
        if(sum_i <= m) ans = max(ans, i);
        else{
            int res = get(1, 1, n, i - 1, sum_i - m);
            ans = max(ans, i - res);
        }
    }
    cout << ans;
    return 0;
}