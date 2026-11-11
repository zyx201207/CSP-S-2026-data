#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
ll ax[maxn],f[maxn],g[maxn],id;
int ap[maxn],in;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int ic,it;
    cin>>ic>>it;
    while(it--){
        scanf("%d %lld",&in,&id);
        int p=1;
        rep(i,1,in){
            scanf("%lld",ax+i);
            while(p<i&&ax[i]-ax[p]>id)p++;
            ap[i]=p;
            // cout<<i<<' '<<ap[i]<<endl;
        }
        ap[in+1]=in+1;
        ll ans=0;
        rep(i,1,in){
            f[i]=1;
            g[i]=0;
            if(ap[i]<i)ans+=g[ap[i]];
            if(ap[i]<i-1){
                int p1=ap[ap[i]+1],p2=ap[ap[i]+2];
                if(p1<p2&&p1<ap[i]){
                    ans+=min(p2-p1,ap[i]-p1);
                    if(p1==ap[ap[i]])ans+=f[ap[ap[i]+1]]-1;
                }
            }
            if(ap[i]==ap[i+1])continue;
            f[i]+=min(i-ap[i],ap[i+1]-ap[i]);
            if(ap[i]==i)continue;
            f[i]+=f[ap[i]]-1;
            g[i]+=g[ap[i]];
            if(ap[i]<i-1){
                int p1=ap[ap[i]+1],p2=ap[ap[i]+2];
                if(p1<p2&&p1<ap[i]&&ap[i]+1<ap[i+1]){
                    g[i]+=min(p2-p1,ap[i]-p1);
                    if(p1==ap[ap[i]])g[i]+=f[ap[ap[i]+1]]-1;
                }
                // if(ap[i]+1==ap[i+1]||ap[ap[i]+1]==ap[ap[i]+2]||ap[ap[i]+1]==ap[i]+1)continue;
                // g[i]+=ap[ap[i]+2]-ap[ap[i]+1]+f[ap[ap[i]+1]]-1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}