#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=1;i<=(n);++i)
#define lop(i,n) for(int i=(n);i;--i)
#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
double Time(){
    return 1.*clock()/CLOCKS_PER_SEC;
}
void cmax(int&a,int b){
    if(a<b)a=b;
}
const int N=5e5+7;
int a[N],n,m,sum[N];
int calc(int x,int y){
    // if(y==4236)
    // cout<<sum[x-1]<<" "<<sum[y]<<"\n";
    return a[y]*(y-x+1)-(sum[y]-sum[x-1]);
}
int solve(){
    cin>>n>>m;
    rep(i,n)cin>>a[i];
    sort(a+1,a+1+n);
    rep(i,n)sum[i]=sum[i-1]+a[i];
    int ans=0,j=1;
    rep(i,n){
        while(j<i&&calc(j,i)>m)++j;
        // if(i-j+1==4236){
        //     int bro=0;
        //     rep(i,4236)bro+=a[i];
        //     // cout<<a[4236]*4236-bro<<"\n";
        //     // cout<<bro<<"\n";
        //     cout<<calc(j,i)<<" "<<m<<"\n";
        //     cout<<j<<" "<<i<<"\n";
        //     exit(0);
        // }
        cmax(ans,i-j+1);
    }
    cout<<ans<<"\n";
    return 0;
}
main(){
    FILE("crystal");
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)solve();
    // cerr << Time() << "\n";
    return 0;
}