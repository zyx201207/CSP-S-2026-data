#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n,ans = 0;
struct Node{
    ll val;
    char ch;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].val >> a[i].ch;
    int l = 1,r = n;
    while(l < r){
        if(a[l].val < a[r].val){
            if(a[l].ch != a[r].ch) ans += a[l].val;
            a[r].val -= a[l].val,a[l].val = 0;l += 1;
        }
        else if(a[l].val > a[r].val){
            if(a[l].ch != a[r].ch) ans += a[r].val;
            a[l].val -= a[r].val,a[r].val = 0;r -= 1;
        }
        else if(a[l].val == a[r].val){
            if(a[l].ch != a[r].ch) ans += a[l].val;
            a[l].val = a[r].val = 0;l += 1,r -= 1;
        }
    }
    cout << ans;
    return 0;
}
