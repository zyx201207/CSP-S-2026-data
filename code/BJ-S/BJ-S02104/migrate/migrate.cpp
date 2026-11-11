#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int nxt[2000009];
int pre[2000009];
int a[2000009];
int P[2000009];
int N[2000009];
int jn_[2000009];
int sn[2000009];
int jp[2000009];
int sp[2000009];
int n,d;
void _main(){
    cin>>n>>d;
    for(int i=1;i<=n+2;i++){
        nxt[i]=pre[i]=P[i]=N[i]=jn_[i]=sn[i]=jp[i]=sp[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int zz;
    zz=1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[zz]>d){
            ++zz;
        }
        pre[i]=zz;
    }
    zz=n;
    for(int i=n;i>=1;i--){
        while(a[zz]-a[i]>d){
            --zz;
        }
        nxt[i]=zz;
    }
    for(int i=1;i<=n;i++){
        if(nxt[pre[i]]==i){
            P[i]=pre[i];
        }
        if(pre[nxt[i]]==i){
            N[i]=nxt[i];
        }
    }
    for(int i=1;i<=n;i++){
        jn_[nxt[i]]++;
        jp[pre[i]]++;
    }
    for(int i=1;i<=n;i++){
        sn[i]=jn_[i]+sn[P[i]];
    }
    for(int i=n;i>=1;i--){
        sp[i]=jp[i]+sp[N[i]];
    }
    int ans;
    ans=0;
    for(int i=1;i<n;i++){
        if(pre[i+1]<i&&nxt[i]>i+1){
            int u,v;
            u=v=0;
            if(pre[i]!=pre[i+1]||!P[i+1]){
                u=jn_[i+1];
            }else{
                u=sn[i+1];
            }
            if(nxt[i]==i+1){
                u--;
            }
            if(nxt[i+1]!=nxt[i]||!N[i]){
                v=jp[i];
            }else{
                v=sp[i];
            }
            if(pre[i+1]==i){
                v--;
            }
            ans+=u*v;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        _main();
    }
    return 0;
}
