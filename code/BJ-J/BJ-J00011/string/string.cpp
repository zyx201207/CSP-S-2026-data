/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct str{
    ll t, st, en;
    char ch;
}a[200010];
string s[200010];
ll vis[200010];
char v[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ll l = 0;
    a[0].st = 0, a[0].en = 0;
    vis[0] = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i].t >> a[i].ch;
        a[i].st = a[i - 1].en + 1;
        a[i].en = a[i].st + a[i].t - 1;
        l += a[i].t;
        vis[i] = vis[i - 1] + a[i].t;
        v[i] = a[i].ch;

    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        ll end1 = l + 1- a[i].st;
        ll sta1 = l + 1 - a[i].en;
        ll q = lower_bound(vis + 1, vis + 1 + n, end1) - vis;
        ll p = lower_bound(vis + 1, vis + 1 + n, sta1) - vis;
        if(p == q)p--;
        if(v[q] != a[i].ch && v[p] != a[i].ch)cnt += vis[q] - vis[p] +1;
        if(a[i].st > l / 2)break;
    }
    cout << cnt;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
struct str{
    int t, st, en;
    char ch;
}a[200010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    string s = " ";
    long long l = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i].t >> a[i].ch;
        for(int j = 1;j <= a[i].t;j++){
            s += a[i].ch;
        }
        l += a[i].t;
    }
    long long cnt = 0;
    for(int i = 1;i <= l / 2 + 1;i++){
        if(s[i] != s[l + 1 - i])cnt++;
    }
    cout << cnt;
    return 0;
}
