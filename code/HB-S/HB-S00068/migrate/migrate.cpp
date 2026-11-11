#include <bits/stdc++.h>
using namespace std;
const int N=2000100;
using ll=long long;
int cid,T,n,b[N],b2[N],dis[N],st[N],ed[N];
ll d,a[N],s[N],f[N];
void WZH(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++)b[i]=lower_bound(a+1,a+1+n,a[i]-d)-a,b2[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++)f[j]=dis[j]=st[j]=ed[j]=s[j]=0;
        for(int j=i;j<=n&&b2[j]!=j;j=b2[j])dis[j+1]++;
        for(int j=i;j<=n;j++)dis[j]+=dis[j-1];
        for(int j=i;j<=n;j++)if(!st[dis[j]])st[dis[j]]=j;
        for(int j=n;j>=i;j--)if(!ed[dis[j]])ed[dis[j]]=j;
        f[i]=s[i]=1;
        for(int j=i+1;j<=n;j++){
            int l=max(b[j],st[dis[j]-1]),r=ed[dis[j]-1];
            if(l<=r)f[j]=s[r]-s[l-1];
            s[j]=s[j-1]+f[j];
            if(f[j]==2)ans++;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&cid,&T);
    while(T--)WZH();
    return 0;
}