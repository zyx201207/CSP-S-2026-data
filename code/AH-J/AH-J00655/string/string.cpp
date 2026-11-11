#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i)cin >> a[i] >> b[i];
    unsigned long long ans = 0;
    unsigned long long rr = n,t = 0;
    for(int i = 1;;){
        if(t + a[i] > t + a[rr]){
            if(b[i] != b[rr]) ans += a[rr];
            t += a[rr],a[i] -= a[rr];
            rr --;
        }
        else{
            if(b[i] != b[rr]) ans += a[i];
            t += a[i],a[rr] -= a[i];
            if(a[rr] == 0)rr --;
            ++ i;
        }
        if(i >= rr)return cout << ans,0;
    }
    cout << ans;
    return 0;
}
/*
!?区区?!
*/
