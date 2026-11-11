#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ls,sl,ans,x[2000005],q[2000005],h[2000005];
inline void sv(){
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> x[i];
        ls=x[i]-x[i-1];
    }
    sl=(d/ls)*2;
    ans=n-sl+1;
    cout << max(ans,(int)0) << "\n";
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin >> c >> t;
    while(t--){
        sv();
    }
    return 0;
}
