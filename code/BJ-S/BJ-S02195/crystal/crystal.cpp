// Wyh is extremely cute
// I love Wyh
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=5e5+10;
int n,m;
int a[maxn],f[maxn];
inline void ipt(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
inline void init(){
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
    // for(int i=1;i<=n;i++)printf("%lld ",f[i]);
    // printf("\n");
}
inline void solve(){
    int ans=1;
    for(int i=2;i<=n;i++){
        int l=1,r=i,s=i;
        while(l<=r){
            int mid=l+r>>1;
            // printf("= %lld %lld %lld\n",i,mid,(i-mid+1)*a[i]-(f[i]-f[mid-1]));
            if((i-mid+1)*a[i]-(f[i]-f[mid-1])<=m){
                s=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-s+1);
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ipt();
    init();
    solve();
    return 0;
}