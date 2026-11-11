#include <bits/stdc++.h>
using namespace std;

//Oct31==Dec25?
typedef long long ll;
const int N = 5e5+10;
ll n, m;
ll a[N], s[N];
ll tree[N<<2], tag[N<<2];
ll ls(ll x){return x << 1;}
ll rs(ll x){return x << 1|1;}
void push_up(ll p){
    tree[p] = tree[ls(p)]+tree[rs(p)];
}
void build(ll p, ll pl, ll pr){
    if(pl == pr){
        tree[p] = s[pl];    return;
    }
    ll mid = (pl+pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid+1, pr);
    push_up(p);
}
void addtag(ll p, ll pl, ll pr, ll d){
    tree[p] += (pr-pl+1)*d;
    tag[p] += d;
}
void push_down(ll p, ll pl, ll pr){
    if(tag[p]){
        ll mid = (pl+pr) >> 1;
        addtag(ls(p), pl, mid, tag[p]);
        addtag(rs(p), mid+1, pr, tag[p]);
        tag[p] = 0;
    }
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d){
    if(L <= pl && pr <= R){
        addtag(p, pl, pr, d);
        return;
    }
    push_down(p, pl, pr);
    ll mid = (pl+pr) >> 1;
    if(L <= mid)    update(L, R, ls(p), pl, mid, d);
    if(R > mid)     update(L, R, rs(p), mid+1, pr, d);
    push_up(p);
}
ll query(ll L, ll R, ll p, ll pl, ll pr){
    if(L <= pl && pr <= R)  return tree[p];
    push_down(p, pl, pr);
    ll mid = (pl+pr) >> 1, res = 0;
    if(L <= mid)    res += query(L, R, ls(p), pl, mid);
    if(R > mid)     res += query(L, R, rs(p), mid+1, pr);
    return res;
}
int main(){
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    ll maxn = -1e18;
    bool flag = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    sort(a+1, a+1+n);
    for(int i = 3;i <= n;i++)
        if(a[i]-a[i-1] != a[i-1]-a[i-2]){flag = false;break;}
    if(flag){
        cout << m/(a[2]-a[1])+1;
        return 0;
    }
    for(int i = 1;i <= n;i++)
        s[i] = maxn-a[i];
    build(1, 1, n);
    ll ans = 0;
    for(int i = n;i >= 1;i--){
        if(i != n)  update(1, n, 1, 1, n, a[i]-a[i+1]);
        ll l = 1, r = i;
        while(l <= r){
            ll mid = (l+r) >> 1;
    //        cout << mid << ' ' << i << ' ' << query(mid, i, 1, 1, n) << ' ' << endl;
            if(query(mid, i, 1, 1, n) <= m) r = mid-1;
            else                            l = mid+1;
        }
        ans = max(ans, i-l+1);
      //  cout << ans << endl << endl;
        if(l == 1)  break;
    }
    cout << ans << endl;
    return 0;
}
