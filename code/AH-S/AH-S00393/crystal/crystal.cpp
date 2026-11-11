#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL n,m,a[N];
LL ans=0,maxn=0,sum=0,s;
bool ok=true;
map<LL,LL> cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(LL i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        if(a[i]!=i) ok=false;
        cnt[a[i]]++;
        s=max(s,a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(LL i=n;i>=1;i--){
            ans=1,sum=0;
            for(LL j=i-1;j>=1;j--){
                sum+=(a[i]-a[j]);
                if(sum>m) break;
                ans++;
            }
            maxn=max(maxn,ans);
        }
        printf("%lld",maxn);
        return 0;
    }
    if(n>5000&&s<=100){
        LL mm=m;
        for(LL i=s;i>=-s;i--){
            ans=cnt[i];mm=m;
            for(LL j=i-1;j>=-s;j--){
                if(cnt[j]==0) continue;
                LL x=i-j;
                LL y=min(cnt[j],mm/x);
                ans+=y; mm-=(i-j)*y;
                if(y<cnt[j]) break;
            }
            maxn=max(maxn,ans);
        }
        printf("%lld",maxn);
        return 0;
    }
    LL gc=a[2]-a[1];
    for(LL k=n-1;k>=1;k--){
        if(gc*((k+1)*k)/2<=m) {
            ans=k;
            break;
        }
    }
    cout<<endl;
    printf("%lld",ans+1);
    return 0;
}
