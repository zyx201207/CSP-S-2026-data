#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2000005;
int c,t,n,d,x[N],nxt[N],f[N][3],g[N][2];
int calc1(int l,int r){
    if(l>r) return 0;
    if(l==r) return g[r][0];
    else return g[r][1];
}
int calc2(int l,int r){
    if(l==r) return f[r][0];
    else if(l+1==r) return f[r][1];
    else return f[r][2];
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    for(int cs=1;cs<=t;cs++){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int l=n,r=n;l;l--){
            while(x[r]-x[l]>d) r--;
            nxt[l]=r;
        }
        f[n][0]=f[n][1]=f[n][2]=0;
        g[n][0]=1,g[n][2]=2;
        for(int i=n-1;i;i--){
            g[i][0]=calc1(i+1,nxt[i])+1;
            g[i][1]=calc1(max(nxt[i-1],i)+1,nxt[i])+2;
            if(i==nxt[i]) f[i][0]=0;
            else ans+=(f[i][0]=calc2(i+1,nxt[i]));
            if(i>1){
                if(nxt[i-1]==nxt[i]) f[i][1]=calc1(i+1,nxt[i-1]);
                else f[i][1]=max(nxt[i-1]-i,0ll)+calc2(max(nxt[i-1],i)+1,nxt[i]);
            }
            if(i>2){
                if(nxt[i-1]==nxt[i]) f[i][2]=calc1(max(i,nxt[i-2])+1,nxt[i-1]);
                f[i][2]=max(nxt[i-1]-max(nxt[i-2],i),0ll)+calc2(max(nxt[i-1],i)+1,nxt[i]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}