#include<bits/stdc++.h>
using namespace std;
//#define int long long;
#define rep(x,y,z) for(register int x=y;x<=z;++x)
#define per(x,y,z) for(register int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
const int N=1000005;
int n,k;
void solve1(){
    cin>>n>>k;
    rep(i,1,n-1){
        int u,v;
        cin>>u>>v;
    }
    if(n==k)cout<<"0"<<endl;
    else cout<<"1"<<endl;
    return;
}
void solve2(){
    cin>>n>>k;
    rep(i,1,n-1){
        int u,v;
        cin>>u>>v;
    }
    if(n==k)cout<<"0"<<endl;
    else if(k>=n/2)cout<<"1"<<endl;
    else cout<<ceil(1.0*((n-1)/2-k)/4)+1<<endl;
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        if(c==1)solve1();
        else solve2();
    }
    return 0;
}
