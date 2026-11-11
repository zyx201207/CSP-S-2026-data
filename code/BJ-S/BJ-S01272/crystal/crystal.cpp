#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int add2(int x,int y){
    add(x,y);
    return x;
}
int qpow(int a,ll b){
    int mul=1;
    for(;b;b>>=1,a=(ll)a*a%MOD) if(b&1) mul=(ll)mul*a%MOD;
    return mul;
}
const int N=500005;
int n;
ll m,a[N],s[N];
void __INIT__(){}
void __SOLVE__(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        chkmax(ans,i-l+1);
    }
    printf("%d\n",ans);
}
int main(){
    #ifndef JZQ
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    int T=1;
    // scanf("%d",&T);
    __INIT__();
    while(T--) __SOLVE__();
    return 0;
}