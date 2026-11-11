#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c)    for(int i=(a);i>=(b);i-=(c))
#define pb push_back

using namespace std;

const int maxn=5.2e5;

template<typename T> void chkmax(T &x,const T&y){
    x=(x>y?x:y);
}
template<typename T> void chkmin(T &x,const T&y){
    x=(x<y?x:y);
}

struct BIT{
    int num[maxn],n;
    inline int lb(int x){   return x&(-x);}
    void padd(int p,int v){
        p++;while(p<=n){    num[p]+=v;p+=lb(p);}
    }
    int qsum(int p){
        p++;int ans=0;
        while(p){   ans+=num[p];p-=lb(p);}
        return ans;
    }
};

int a[maxn];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    rep(i,1,n,1)    cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0,su=0,l=1;
    rep(i,1,n,1){
        su+=(a[i]-a[i-1])*(i-l);
        while(su>m){
            su-=a[i]-a[l];l++;
        }
        chkmax(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}