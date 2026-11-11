#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn],maxi = -1e12,mini = 1e12,n,m;

bool check(ll x){
    ll cnt = 0;
    for(int i = 1;i + x - 1 <= n;i++){
        ll y = i + x - 1;
        for(int j = i;j <= y;j++){
            cnt += a[y] - a[j];
        }
        if(cnt <= m){
            //cout << cnt << ' ' << x << ' ' << i << ' ' << y << endl;
            return true;
        }
        cnt = 0;
    }
    return false;
}

ll find(){
    ll l = 1,r = n,mid;
    while(l +1 < r){
        mid = (l + r) / 2;
        if(check(mid))l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin >> n >> m;
    for(int i =1;i <= n;i++){
        cin >> a[i];
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    sort(a + 1,a + n + 1);
    cout << find();
    return 0;
}
