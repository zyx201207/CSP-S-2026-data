#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define test(x) freopen(x".in","r",stdin)
#define LL long long
#define db double
#define i128 __int128
#define lb(x) (x&-x)
#define fir first
#define sec second
const int N=5e5+5,inf=1e9;const LL INF=1e18;
int n,ans;LL m,a[N],s[N];
void solve(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+1+n),reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=i,r=n,mid,tmp=0;
        while(l<=r) mid=(l+r)>>1,(mid-i)*a[i]<=m+(s[mid]-s[i])?(tmp=mid,l=mid+1):r=mid-1;
        ans=max(ans,tmp-i+1);
    }
    printf("%d\n",ans);
}
int main(){
    FILE("crystal");
    int T=1;// scanf("%d",&T);
    while(T--) solve();
    return 0;
}
/*
我终于结束我的流浪当你说你愿意到 everywhere I go
when nobody got me, nobody trusted me, nobody I knew
——Rapeter《Royal Blue》
*/