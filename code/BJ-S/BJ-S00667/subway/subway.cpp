#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;
ll w[500005];
ll k,x,y;
ll a[505][10005],t[505][10005];
ll ans = 0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
        for(int i = 1;i <= m;i++){
            cin>>w[i];
        }
        for(int i = 1;i <= n;i++){
            cin>>k;
            for(int j = 1;j <= 2k;j++){
                cin>>a[i][j]>>t[i][j];
            }
        }
        for(int i = 1;i <= n;i++){
            cin>>x>>y;
            ans = ans + w[x] + w[y];
            cout<<ans<<endl;
        }
    return 0;
}
