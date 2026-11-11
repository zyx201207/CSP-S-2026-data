#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2145140];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(a,0,sizeof(a));
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        int diff = a[n] - a[n-1];
        if(a[n] - a[1] >= 2*d-1 && diff < d)
            cout << n-2*d+1 << endl;
        else cout <<0 << endl;
    }
    return 0;
}
