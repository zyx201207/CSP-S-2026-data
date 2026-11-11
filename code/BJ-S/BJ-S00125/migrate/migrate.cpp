#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fr first 
#define sc second 
#define mk make_pair 
#define pb push_back
const int MAXN=2000010,N=1010,inf=3e18;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,d,ans,a[MAXN],ls[MAXN],nx[MAXN],L[MAXN],R[MAXN];
int ld[MAXN],rd[MAXN];
void slv(){ans=0;
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        ls[i]=lower_bound(a+1,a+n+1,a[i]-d)-a,
        nx[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        ld[nx[i]]++;
        rd[ls[i]]++;
    }
    for(int i=1;i<=n;i++){
        L[i]=1;
        if(ls[i]!=i&&nx[ls[i]]==i)L[i]+=L[ls[i]];
        L[i]+=ld[i]-(nx[i]==i||nx[ls[i]]==i);
    }
    for(int i=n;i>=1;i--){
        R[i]=1;
        if(nx[i]!=i&&ls[nx[i]]==i)R[i]+=R[nx[i]];
        R[i]+=rd[i]-(ls[i]==i||ls[nx[i]]==i);
    }
    for(int i=1;i<=n;i++)if(nx[i]!=i&&nx[i]!=n&&nx[i]-1!=i){
        int y=nx[i]-1;
        if(ls[ls[nx[nx[i]]]]==i){
            if(ls[nx[nx[i]]]==y)ans+=L[i]*R[nx[nx[i]]];
        }
        else if(ls[nx[nx[i]]]==y)ans+=R[nx[nx[i]]];
        // cout<<i<<":"<<ans<<endl;ans=0;

        if(ls[y]==i)ans+=L[i]*(rd[y]-(ls[nx[nx[i]]]==y));
        else ans+=rd[y]-(ls[nx[nx[i]]]==y);
        // cout<<i<<":"<<ans<<endl;ans=0;
    }
    printf("%lld\n",ans);

    // for(int i=1;i<=n;i++)
    //     cout<<ls[i]<<" "<<nx[i]<<" "<<L[i]<<" "<<R[i]<<" "<<ld[i]<<" "<<rd[i]<<endl;
    for(int i=1;i<=n;i++)a[i]=ls[i]=nx[i]=L[i]=R[i]=ld[i]=rd[i]=0;
}
signed main(){
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    int __=read(),_=read();while(_--)
    slv();
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
}