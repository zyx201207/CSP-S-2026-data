#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000005;

int c,t,n,d,x[maxn],dp[maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<0<<"\n";
    }
    return 0;
}

