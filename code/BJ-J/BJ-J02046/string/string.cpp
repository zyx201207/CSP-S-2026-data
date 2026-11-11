#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct node{
    int x;
    char c;
};
ll ans;
ll len;
node a[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    //O(n)
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].c;
        len += a[i].x;
    }
    ll mid = len / 2 + 1, cnt = 0;
    ll l = 1, r = n;//1 ~ n i;
    while(cnt < mid && l < r){
        if(a[l].c != a[r].c){
            ans += min(a[l].x, a[r].x);
           // cout << ans << " ";
        }
        if(a[l].x < a[r].x){
            l++;
        }else{
            r--;
        }
        cnt += min(a[l].x, a[r].x);
    }
    if(ans > mid-1)cout << mid-1;
    else cout << ans;
    return 0;
}
