#include <bits/stdc++.h>
using namespace std;
int c,T,n;
long long a[2000005],d;
int l[2000005],r[2000005],bg[2000005],ed[2000005],C[2000005],C2[2000005];
int main(){freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),C[i]=C2[i]=0;
        for(int i=1;i<=n;i++){
            r[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            l[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
            C[l[i]]++; C2[r[i]]++;
            if(r[l[i]]==i) ed[i]=ed[l[i]]+C2[i];
            else ed[i]=1;
        }
        for(int i=n;i>=1;i--){
            if(l[r[i]]==i) bg[i]=bg[r[i]]+C[i];
            else bg[i]=1;
        }
        for(int i=1;i<=n;i++){
            bg[i]--; ed[i]--;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(r[i]-1>i&&r[r[i]]>r[i]&&l[r[r[i]]]==r[i]-1&&l[l[r[r[i]]]]==i) ans+=1ll*ed[i]*bg[r[r[i]]];
            if(r[i]-1>i&&r[r[i]]>r[i]&&l[r[r[i]]]==r[i]-1) ans+=bg[r[r[i]]];
            if(r[i]-1>i)
                ans+=1ll*((l[r[i]-1]==i)*ed[i]+1)*C[r[i]-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
