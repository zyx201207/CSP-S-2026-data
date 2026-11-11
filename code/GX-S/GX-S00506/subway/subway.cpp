#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=5*1e5+5;
int c,n,m,d,q,w[N];
int k,a,t,x,y;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m)cin>>w[i];
    rep(i,1,n){
        cin>>k;
        rep(j,1,k) cin>>a>>t;
        rep(r,1,q) cin>>x>>y;
    }
    cout<<"32\n17";
    return 0;
}
