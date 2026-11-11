#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[500005];
vector<ll> a;
//priority_queue<ll, vector<ll>, greater<ll>> q;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;
    int ans = 0;
    cin >> n >> m;
    ll s = 0;
    for(int i = 0 ; i < n ; i ++){
        ll v;
        cin >> v;
        a.push_back(v);
    }
    sort(a.begin(), a.end());
    for(int i = 0 ; i < n ; i ++){
        sum[i] = (i == 0 ? 0 : sum[i-1]) + a[i];
    }

    for(int i = 0 ; i < n ; i ++){
        int l = 0, r = i;
        int cant = 0;
        while(r != l){
            int mid = (r + l) >> 1;
            if(a[i] * (i - mid) - (sum[i] - sum[mid]) > m){
                cant = 1;
                l = mid+1;
            }else{
                cant = 0;
                r = mid;
            }
        }
        ans = max(ans, i - r + 1 + (cant ? -1 : 0));
    }
    cout << ans << endl;
	return 0;
}
