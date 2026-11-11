#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
long long n,m,use,ans=0,a[N],d[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
    int p1=1;
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]+d[i];
        use+=1ll*d[i]*(i-p1);
        while(use>m) use-=s[i]-s[p1],p1++;
        ans=max(ans,1ll*(i-p1+1));
    }
    cout<<ans;
    return 0;
}
