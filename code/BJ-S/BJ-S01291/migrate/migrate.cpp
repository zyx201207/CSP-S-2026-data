#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
const int N=1e8+5;
int c,t,n,d;
int x[N];
void solve(){
    cin>>n>>d;
     rep(i,1,n) cin>>x[i];
     cout<<0<<'\n';
}
void suba(){
    cin>>n>>d;
    rep(i,1,n) cin>>x[i];
    int dif=x[2]-x[1];
    int len=0;
    if(dif>d) cout<<0<<'\n';
    else{
        len=(2*d-1)/dif;
        cout<<max(n-len,0ll)<<'\n';
    }

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(c==11||c==12) suba();
        else solve();
    }
    return 0;

}

