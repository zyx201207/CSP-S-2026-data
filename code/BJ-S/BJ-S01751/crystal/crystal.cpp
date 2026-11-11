#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int tmpi = 1;
    for(int i = 1;i <= n;i++){
        m -= (a[i] - a[i - 1]) * (i - tmpi);
 //       cout << m << '\n';
        while(m < 0){
            m += (a[i] - a[tmpi]);
            tmpi++;
        }
        ans = max(ans,i - tmpi + 1ll);
    }
    cout << ans;
    return 0;
}
