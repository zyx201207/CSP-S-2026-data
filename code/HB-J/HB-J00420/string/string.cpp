#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
constexpr int N = 2e5+10;
char c[N];
int n, a[N];
ll len;
#define fi first
#define se second

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i];
        len += a[i];
    }
    ll ans = 0;
    ll tar = len/2, now = 0;
    if(len%2 == 1) tar += 1;
    ll cid = -1, nid;
    //cout << tar << '\n';
    for(int i = 1; i <= n; ++i){
        if(now+a[i] >= tar && cid == -1){
            cid = i;
            nid = now+a[i]-tar;
        }
        now += a[i];
        //cout << now << ' ';
    }
    //cout << cid << ' ' << nid;
    pair<ll, ll> ed, st;
    if(len%2 == 1){
        ed.se = nid-1, ed.fi = cid;
        if(ed.se < 1){
            ed.fi -= 1;
            ed.se = a[ed.fi];
        }
        st.se = nid+1, st.fi = cid;
        if(st.se > a[st.fi]){
            st.fi += 1;
            st.se = 1;
        }
    }else{
        ed.fi = cid, ed.se = nid;
        st.se = nid+1, st.fi = cid;
        if(st.se > a[st.fi]){
            st.fi += 1;
            st.se = 1;
        }
    }
    //printf("%d %d\n%d %d", ed.fi, ed.se, st.fi, st.se);
    pair<ll, ll> id = {1, 1}, jd = {n, a[n]};
    while(id.fi < jd.fi){
        if(c[id.fi] != c[jd.fi]){
            ll ri = a[id.fi]-id.se+1;
            ll rj = jd.se;
            if(ri < rj){
                id.fi += 1, id.se = 1;
                jd.se -= ri;
            }else if(ri > rj){
                jd.fi -= 1;jd.se = a[jd.fi];
                id.se += rj;
            }else{
                id.fi += 1, id.se = 1;
                jd.fi -= 1;jd.se = a[jd.fi];
            }
            ans += min(ri, rj);
        }else{
            ll ri = a[id.fi]-id.se+1;
            ll rj = jd.se;
            if(ri < rj){
                id.fi += 1, id.se = 1;
                jd.se -= ri;
            }else if(ri > rj){
                jd.fi -= 1;jd.se = a[jd.fi];
                id.se += rj;
            }else{
                id.fi += 1, id.se = 1;
                jd.fi -= 1;jd.se = a[jd.fi];
            }
        }
    }
    cout << ans;
    return 0;
}
