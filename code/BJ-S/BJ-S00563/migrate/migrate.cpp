#include<bits/stdc++.h>
#define int long long
#define upbd upper_bound
#define lwbd lower_bound
using namespace std;
const int N=2e6+5;
int n,d,a[N];
namespace baoli{
    int b[N],tol,f[N],g[N];
    inline bool judge(int l,int r){
        for(int i=1;i<=tol;i++)b[i]=f[i]=g[i]=0;
        tol=0;
        for(int i=l;i<=r;i++)b[++tol]=a[i];
        f[1]=g[1]=1;
        for(int i=2;i<=tol;i++){
            int pos=lwbd(b+1,b+tol+1,b[i]-d)-b;
            if(pos>=i)return false;
            f[i]=f[pos]+1;g[i]+=g[pos];
            for(int j=pos+1;j<=min(pos+2,i-1);j++)
                if(f[j]==f[pos])g[i]+=g[j];
        }
        return g[tol]==2;
    }
    inline void work(){
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans+=judge(i,j);
        cout<<ans<<'\n';
        return;
    }
}
namespace subA{
    inline void work(){
        int dta=a[2]-a[1],cnt=d/dta,ans=0;
        if(cnt<=1){cout<<0<<'\n';return;}
        for(int k=1;k<=n-1;k++)
            if((k/cnt==1)&&k%cnt==cnt-1)ans+=n-k;
        cout<<ans<<'\n';
        return;
    }
}
namespace subB{
    int L[N],R[N];unordered_map<int,int> t;
    inline void work(){
        for(int i=1;i<=n;i++)R[i]=upbd(a+1,a+n+1,a[i]+d)-R-1;
        for(int i=1;i<=n;i++)L[i]=lwbd(a+1,a+n+1,a[i]-d)-L;
        t.clear();
        for(int i=1;i<=n;i++)t[R[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++)ans+=t[L[i]+1];
        cout<<ans<<'\n';
        return;
    }
}
inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){cout<<0<<'\n';return;}
    int dta=a[2]-a[1];bool flag=true;
    for(int i=3;i<=n;i++)
        if(a[i]-a[i-1]!=dta){flag=false;break;}
    if(n<=300)baoli::work();
    else if(flag)subA::work();
    else subB::work();
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--)solve();
    return 0;
}