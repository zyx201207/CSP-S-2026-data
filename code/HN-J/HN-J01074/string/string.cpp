#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 10;

ll n, cnt, ans;

string s;

struct Node{
    ll x;
    char c;
}a[N];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n;  i++){
        cnt += a[i].x;
        cin >> a[i].x >> a[i].c;
    }
    int l = 1, r = n;
    while(l <= r){
        //cout << l << ' ' << r << '\n';
        if(a[l].c != a[r].c){
            if(a[l].x > a[r].x){
                ans += a[r].x;
                a[l].x -= a[r].x;
                r--;
            }else if(a[l].x == a[r].x){
                ans += a[l].x;
                l++, r--;
            }else{
                ans += a[l].x;
                a[r].x -= a[l].x;
                l++;
            }
        }else{
            if(a[l].x > a[r].x){
                a[l].x -= a[r].x;
                r--;
            }else if(a[l].x == a[r].x){
                l++, r--;
            }else{
                a[r].x -= a[l].x;
                l++;
            }
        }/*
        for(int i = 1; i <= n ;i++){
            cout << a[i].x << ' ';
        }
        cout << '\n';*/
    }
    cout << ans;
    return 0;
}
/*
 89 & 56 = 24

3
2 a
2 b
1 a


2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
