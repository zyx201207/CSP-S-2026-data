#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],l[N],r[N],vs[N],vt[N],pre[N],suf[N],ans;
int tim[N],f[5005][5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;
    if(c<=6) while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) l[i]=r[i]=vs[i]=vt[i]=pre[i]=suf[i]=tim[i]=0;
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
            r[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
            // cerr<<i<<' '<<l[i]<<' '<<r[i]<<'\n';
        }
        ans=0;
        for(int l=1;l<=n;l++){
            int x=l,p=l,cnt=0;
            while(x<n){
                x=r[x],++cnt;
                for(int i=p+1;i<=x;i++) tim[i]=cnt;
                if(p==x) break;
                p=x;
            }
            for(int i=l;i<=n;i++) for(int t=0;t<=tim[i];t++) f[i][t]=0;
            f[l][0]=1;
            for(int i=l;i<=n;i++)
                for(int t=0;t<=tim[i];t++)
                    for(int j=i+1;j<=r[i];j++)
                        f[j][t+1]+=f[i][t];
            for(int i=l;i<=n;i++) if(f[i][tim[i]]==2) ++ans;
        }
        cout<<ans<<'\n';
    }else while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        for(int i=1;i<=n;i++) l[i]=r[i]=vs[i]=vt[i]=pre[i]=suf[i]=0;
        for(int i=1;i<=n;i++){
            l[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
            r[i]=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
            // cerr<<i<<' '<<l[i]<<' '<<r[i]<<'\n';
        }
        vector<array<int,3>>tmp;
        for(int i=1;i<=n;i++) if(r[i]-1>i){
            int L=r[r[i]-2]+1,R=r[r[i]-1];
            if(L>R) continue;
            tmp.push_back({i,L,R});
            vs[i]=1,++vt[L],--vt[R+1];
        }
        for(int i=1;i<=n;i++) vt[i]+=vt[i-1];
        for(int i=1;i<=n;i++) vt[i]=min(vt[i],1ll);
        for(int i=1,j;i<=n;i++){
            if(vs[i]){
                for(j=i-1;j>=1&&!vs[j]&&r[j]>j;j--);
                pre[i]=i-j; // (j,i]
            }
            if(vt[i]){
                for(j=i+1;j<=n&&!vt[j]&&l[j]<j;j++);
                suf[i]=j-i; // [i,j)
            }
        }
        for(auto [i,L,R]:tmp) ans+=pre[i]*(suf[R]+R-L);
        cout<<ans<<'\n';
        // cerr<<tmp.size()<<'\n';
    }
}