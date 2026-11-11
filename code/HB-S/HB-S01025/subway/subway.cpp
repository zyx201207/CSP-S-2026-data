#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int c,q,d;
ll m,n,p,w[N],s[505],x,y;
struct node{
    ll a,t;
}k[255][N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for (ll j=1;j<=n;j++){
        cin>>s[j];
        for (ll i=1;i=s[j];i++) cin>>k[j][i].a>>k[j][i].t;
    }
    while (q--){
        ll ans=0,flag=0;
        cin>>x>>y;
        for (ll j=1;j<=n;j++){
            for (ll i=1;i=s[j];i++){
                if (x==k[j][i].a || y==k[j][i].a) flag++;
            }
        }
        if (flag>=2){
            for (ll j=1;j<=n;j++){
                ans+=k[j][x].t;
                ans+=k[j][y].t;
            }
        }
        else {
            for (ll j=1;j<=n;j++){
                for (ll i=1;i=s[j];i++){
                    ans+=k[j][i].t;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
