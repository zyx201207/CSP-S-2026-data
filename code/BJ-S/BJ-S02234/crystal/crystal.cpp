#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ai, mid, l ,r, cnt, vs, cnt1, ans, k, cnt2, f;
vector <ll> v;
vector <ll> v1;
vector <ll> v2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
       cin >> ai;
       v.push_back(ai);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++){
        if(i == 0){
            cnt++;
            continue;
        }
        if(v[i] != v[i-1]){
            v1.push_back(v[i-1]);
            v2.push_back(cnt);
            ans = max(ans,cnt);
            cnt = 0;
        }
        cnt++;
    }
    v1.push_back(v[n-1]);
    v2.push_back(cnt);
    ans = max(ans,cnt);
    vs = v1.size();
    l = 0, r = vs-1;
    while(l <= r){
        cnt1 = 0, cnt2 = 0, f = 0;
        mid = (l+r) >> 1;
        for(int i = mid-1; i >= 0; i--){
            k = m - cnt1;
            if(k < 0) break;
            if(v2[i]*(v1[mid]-v1[i]) <= k) cnt1 += v2[i]*(v1[mid]-v1[i]), cnt2 += v2[i];
            else {
                cnt2 += k / (v1[mid]-v1[i]);
                f = 1;
                break;
            }
        }
        ans = max(cnt2 + v2[mid],ans);
        if(f) r = mid-1;
        else l = mid+1;
    }
    cout << ans;
    return 0;
}