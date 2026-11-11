#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int c,t,n,d;
int x[N],dp[N];

void solve(){

    cin>>n>>d;

    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=d;j++){
            dp[i]=dp[i-j]+dp[i-j-1];
        }
    }

    cout<<dp[n]-dp[n-d]<<"\n";

    return;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        solve();
    }

    return 0;

}
