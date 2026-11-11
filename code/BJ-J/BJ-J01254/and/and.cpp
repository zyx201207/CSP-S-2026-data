#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll mx, n, cnt[40], a[200005], pw[40], m;

vector<int>vec;

int main(){
    freopen("and.in" , "r", stdin );
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pw[0] = 1;
    for(int i = 1; i <= 35; i++){
        pw[i] = pw[i-1]*2;
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
        for(int j = 0; j <= 35; j++){
            if((a[i] & pw[j]) == pw[j]) cnt[j]++;
        }
    }
    sort(a+1, a+1+n, greater<int>());
    for(int i = 0; i <= 32; i++){
        if(cnt[i] >= m) vec.push_back(i);
    }
    int d = vec.size();
    for(int i = pw[d]-1; i >= 0; i--){
        int cnt = 0;
        ll nd = 0;
        for(int j = 0; j < d; j++){
            if(pw[j] & i) nd+=pw[vec[j]];
        }
        for(int i = 1; i <= n; i++){
            if((a[i] & nd) == nd) cnt++;
            if(a[i] < nd || cnt >= m) break;
        }
        if(cnt >= m){
            cout << nd;
            break;
        }
    }
    return 0;
}
