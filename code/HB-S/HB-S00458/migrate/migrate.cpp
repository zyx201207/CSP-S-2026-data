#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;

    if(c>=13 &&c<=14){
     while(t--){
         int n, q; cin>>n>>q;
         vector < ll > a(n+1);
         for(int i=1;i<=n;i++) cin>>a[i];
         int te = 0; for(int i=1;i<=n;i++){if(a[i]-a[1]<=q && a[n]-a[i]<=q){te=i; break;} }
         ll ans=0;
         for(int i=1;i<=n;i++){
            if(i<te) ans+=(n-te);
         }
         cout<<ans<<"\n";
     }
     return 0;
    }

    while(t--){
        int n, q;cin>>n>>q;
        vector < ll > a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>q) ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
