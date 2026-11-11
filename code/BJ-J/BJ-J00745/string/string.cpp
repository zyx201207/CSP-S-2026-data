#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+5;
int a[N],sa[N],n,t,ans,minn;
char c[N],sc[N];

signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> c[i];
        sa[n-i-1] = a[i];
        sc[n-i-1] = c[i];
    }

    for(int i = 0; i < n; i++){
        while(a[i]){
            minn = min(sa[t],a[i]);
            if(sc[t] != c[i]) ans += minn;
            a[i] -= minn;
            sa[t] -= minn;
            if(!sa[t]) t++;
        }
    }

    cout << ans/2;

    return 0;
}
