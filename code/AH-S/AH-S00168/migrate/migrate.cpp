#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int u,v;
};
ll c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ll n,d,a[2000005];
        vector<mode> g[2000005];
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back({j,1});
                    g[j].push_back({i,1});
                }
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
