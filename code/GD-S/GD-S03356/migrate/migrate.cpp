#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int cid;
int n;
ll x[N],d;
int l[N],r[N];
int f[N],g[N];
void Main() {
    cin>>n>>d;
    for(int i=1;i<=n;++i) {
        cin>>x[i];
    }
    for(int i=1,j=1;i<=n;++i) {
        while(x[i]-x[j]>d) ++j;
        if(j==i) l[i]=0;
        else l[i]=j;
    }
    for(int i=n,j=n;i>=1;--i) {
        while(x[j]-x[i]>d) --j;
        if(j==i) r[i]=0;
        else r[i]=j;
    }
    for(int i=1;i<=n;++i) g[i]=f[i]=0;
    for(int i=1;i<=n;++i) {
        f[i]++;
        if(r[i] && l[r[i]]<i) f[r[i]]++;
        if(r[i] && l[r[i]]==i) f[r[i]]+=f[i];
    }
    for(int i=n;i>=1;--i) {
        g[i]++;
        if(l[i] && r[l[i]]>i) g[l[i]]++;
        if(l[i] && r[l[i]]==i) g[l[i]]+=g[i];
    }
    ll ans=0;
    for(int i=2;i<n-1;++i) if(l[i] && r[i+1]) {
        // ll t=ans;
        if(r[l[i]]==i+1 && l[r[i+1]]==i) {
            ans+=(ll)f[l[i]]*g[r[i+1]];
        }
        int x=max(l[i+1],l[i]+1),y=min(i-1,l[i+2]-1);
        int u=max(i+2,r[i-1]+1),v=min(r[i],r[i+1]-1);
        if(x<=y && l[r[i+1]]==i) ans+=(ll)(y-x+1)*g[r[i+1]];
        if(r[l[i]]==i+1 && u<=v) ans+=(ll)f[l[i]]*(v-u+1);
        if(x<=y && u<=v) ans+=(ll)(y-x+1)*(v-u+1);
        // cout<<i<<' '<<ans-t<<'\n';
    } 
    // map<int,int> C;
    // for(int u=1;u<=n;++u) {
    //     for(int v=u+1;v<=n;++v) {
    //         bool no=0;
    //         vector<int> A;
    //         vector<int> B;
    //         for(int x=u;;) {
    //             A.push_back(x);
    //             if(x==v) break;
    //             if(!r[x]) {no=1; break;}
    //             x=min(v,r[x]);
    //         }
    //         if(no) continue;
    //         for(int x=v;;) {
    //             B.push_back(x);
    //             if(x==u) break;
    //             x=max(u,l[x]);
    //         }
    //         reverse(B.begin(),B.end());
    //         if(A.size()==B.size()) {
    //             int cnt=0,p=0;
    //             for(int i=0;i<A.size();++i) {
    //                 if(A[i]!=B[i]) p=i,++cnt;
    //             }
    //             if(cnt>1) continue;
    //             if(A[p]==B[p]+1) {
    //                 ++ans,C[B[p]]++;
    //                 if(B[p]==3) cout<<u<<' '<<v<<'\n';
    //             }
    //         }
    //     }
    // }
    // for(auto [x,y]:C) cout<<x<<' '<<y<<'\n';
    cout<<ans<<'\n';
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>cid>>t;
    while(t--) Main();
}