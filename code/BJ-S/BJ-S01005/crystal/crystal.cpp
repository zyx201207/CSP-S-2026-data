#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 10;
int a[MAXN],s[MAXN];


int main(){
    freopen("crystal,in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    a[0] = -11451419191;
    for(int i = 1;i <= n;i++){
        s[i] = a[i] - a[i-1];
    }
    ll sum = 0,cnt = 0;
    for(int i = 2;sum + s[i] <= m;i++){
        sum += s[i];
        cnt++;
    }
    cout << cnt + 1;
    return 0;
}
