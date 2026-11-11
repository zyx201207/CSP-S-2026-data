#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+5;
int c,t,n,p[maxn],q[maxn],f[maxn],g[maxn],v[maxn],s[maxn];
long long d,x[maxn];

long long solve(int l,int r){
    if(l>=r) return 0ll;
    long long res=0;
    for(int st=l;st<=r-1;st++){
        f[st]=0,g[st]=1;
        for(int i=0;i<=r-l+1;i++) v[i]=0;
        for(int i=l-1;i<=r;i++) s[i]=0;
        v[0]=st,s[st-1]=0,s[st]=1;
        for(int i=st+1;i<=r;i++){
            int od=max(q[i],st);
            f[i]=f[od]+1,g[i]=0;
            g[i]=min(s[v[f[od]]]-s[od-1],3);
            if(g[i]==2) res++;
            v[f[i]]=max(v[f[i]],i),s[i]=s[i-1]+g[i];
        }
    }
    return res;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        if(n==1){
            printf("0\n");
            continue;
        }
        bool flga=1;
        for(int i=1;i<=n-1;i++) flga&=(x[2]-x[1]==x[i+1]-x[i]);

        for(int i=1;i<=n;i++){
            int l=i,r=n;
            while(l<r){
                int mid=(l+r+1)/2;
                if(x[mid]<=x[i]+d) l=mid;
                else r=mid-1;
            }
            p[i]=l;
        }
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<r){
                int mid=(l+r)/2;
                if(x[mid]>=x[i]-d) r=mid;
                else l=mid+1;
            }
            q[i]=l;
        }
        long long ans=0;

        if(n<=5000){
            int lst=0;
            for(int i=1;i<=n;i++){
                if(p[i]==i) ans+=solve(lst+1,i),lst=i;
            }
            ans+=solve(lst+1,n);
            printf("%lld\n",ans);
        }
        else if(flga==1){
            f[1]=0,g[1]=1;
            for(int i=0;i<=n;i++) v[i]=0,s[i]=0;
            v[0]=1,s[0]=0,s[1]=1;
            for(int i=2;i<=n;i++){
                int od=max(q[i],1);
                f[i]=f[od]+1,g[i]=0;
                g[i]=min(s[v[f[od]]]-s[od-1],3);
                if(g[i]==2) ans+=n-i+1;
                v[f[i]]=max(v[f[i]],i),s[i]=s[i-1]+g[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
