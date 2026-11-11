#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e6 + 10;

int id,T,n,d,a[N];

void solve(){
    if(n == 1) cout << 0 << '\n';
    else if(a[2] - a[1] > d) cout << 0 << '\n';
    else{
        int x = d / (a[2] - a[1]);
        if(x == 1)cout << 0 << '\n';
        else cout << max(0ll,n - 2 * x + 1) << '\n';
    }


}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> id >> T;
    while(T --){
        cin >> n >> d;
        //memset(nxt,0,sizeof(nxt));
        for(int i = 1;i <= n;i ++) cin >> a[i];
        a[n + 1] = 5e18;
        if(id == 11 ||id==12){
            solve();
            continue;
		}
        
    }


    return 0;
}
