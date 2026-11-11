#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 +10;
int a[N];

signed main(){
    int n ,m;
    int maxx = -1e18,maxx1 = -1e18;
    cin >> n >> m;
    for(int i = 1;i<= n;i++){
        cin >> a[i];
        maxx= max(maxx,a[i]);
    }
    if(m == 1) cout << maxx <<endl;
    else if(m == 2){
        for(int i = 1;i<= n;i ++){
            for(int j = i + 1;j <= n;j ++){
                maxx1 = max(maxx1,a[i]&a[j]);
            }
        }
        cout << maxx1;
    }
    else{
        int ans = 0;
        sort(a + 1,a +n + 1);
        for(int i = 1;i < m;i ++){
            ans += (a[n] & a[n - 1]);
            n --;
        }
        cout << ans << endl;
    }
    return 0;
}
