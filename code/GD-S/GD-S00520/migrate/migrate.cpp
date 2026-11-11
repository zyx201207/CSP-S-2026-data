#include<bits/stdc++.h>
using namespace std;
//#define int long long;
#define rep(x,y,z) for(register int x=y;x<=z;++x)
#define per(x,y,z) for(register int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
const int N=2000005;
int n,d,a[N],l[N],r[N],j=1,ans;
void init(){
    rep(i,1,n)l[i]=0,r[i]=0;
    ans=0;
}
void solve(){
    cin>>n>>d;
    init();
    rep(i,1,n)cin>>a[i];
    rep(i,1,n){
        while(j<i&&a[i]-a[j]>d)r[j]=i-1,j++;
        l[i]=j;
        if(i==n)while(j<=i)r[j++]=i;
    }
    int nl=l[n],nr=r[1];
    if(nr-nl>1){cout<<0<<endl;return;}
    if(nr-nl==1){
        int cnt1=1,p1=1,cnt2=1,p2=n;
        while(r[p1+1]==r[p1])++p1,++cnt1;
        while(l[p2-1]==l[p2])--p2,++cnt2;
        cout<<cnt1*cnt2<<endl;
        return;
    }
    if(nr==nl){
        int cnt1=1,p1=1,cnt2=1,p2=n;
        while(r[p1+1]==r[p1])++p1,++cnt1;
        while(l[p2-1]==l[p2])--p2,++cnt2;
        rep(i,p1+1,n){
            if(r[i]-l[n]==2)ans+=cnt2;
            else break;
        }
        per(i,p2-1,1){
            if(r[1]-l[i]==2)ans+=cnt1;
            else break;
        }
        cout<<ans<<endl;
        return;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}//teshuxingzhib