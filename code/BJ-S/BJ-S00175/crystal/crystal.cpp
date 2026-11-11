#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[N],mi = 1e9;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        mi = min(mi,a[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == mi)  a[i] += 1;
        m -= 1;
        mi = min(mi,a[i]);
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == a[i+1]){
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}
