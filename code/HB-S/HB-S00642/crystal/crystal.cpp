#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
typedef long long ll;
ll n,m,ans = 0,sum = 0;
ll a[N];
queue<ll> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        while(q.size()){
            ll sz = q.size();
            if(sz * a[i] - sum > m) q.pop();
            else break;
        }
        q.push(a[i]);sum += a[i];
        ans = max(ans,int(q.size()) * 1ll);
    }
    cout << ans;
    return 0;
}
