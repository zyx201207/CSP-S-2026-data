#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll d,x[2000005];
int nxt[2000005],lst[2000005];
ll f[2000005][2][2][2];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=0;i<=n;i++){
        for(int o=0;o<=1;o++) f[i][0][0][o]=f[i][0][1][o]=f[i][1][0][o]=f[i][1][1][o]=0;
    }
    int r=1;
    for(int i=1;i<=n;i++){
        while(r<n&&x[r+1]-x[i]<=d) r++;
        nxt[i]=r;
    }
    int l=n;
    for(int i=n;i>=1;i--){
        while(l>1&&x[i]-x[l-1]<=d) l--;
        lst[i]=l;
    }
    ll ans=0;
    // for(int u=1;u<=n;u++){
    //     for(int v=nxt[u]+1;v<=n;v++){
    //         int now=u,bFst=1,cnt=0;
    //         while(now!=v){
    //             int Nx=min(nxt[now],v);
    //             if(Nx==now){
    //                 cnt=-1;
    //                 break;
    //             }
    //             if(bFst==0&&x[Nx]-x[now-1]<=d) cnt++;
    //             if(cnt>1) break;
    //             if(bFst==0&&now>=3&&x[Nx]-x[now-2]<=d){
    //                 cnt=-1;
    //                 break;
    //             }
    //             bFst=0;
    //             now=Nx;
    //         }
    //         if(cnt==1){
    //             cout<<u<<" "<<v<<"\n";
    //             // ans++;
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++){
        f[i][1][0][0]++;
        //分为正常走和被v截断
        //前者记入f，后者直接记入答案
        if(nxt[i]!=i){
            for(int o=0;o<=1;o++){
                int bo=(nxt[i]-1>i&&i>1&&x[nxt[i]-1]-x[i-1]<=d);
                f[nxt[i]][0][0][0]+=f[i][1][0][o];
                if(f[i][0][0][o]||f[i][0][1][o]){
                    if(i<=2||x[nxt[i]]-x[i-2]>d){
                        if(i>1&&x[nxt[i]]-x[i-1]<=d){
                            if(o){

                            }else f[nxt[i]][0][1][bo]+=f[i][0][0][o];
                            // cerr<<nxt[i]<<" "<<i<<"\n";
                        }else{
                            f[nxt[i]][0][0][bo]+=f[i][0][0][o];
                            f[nxt[i]][0][1][bo]+=f[i][0][1][o];
                        }
                    }
                }
            }
        }
        int pos=lst[i];
        if(pos<i) ans+=f[pos][0][1][0]+f[pos][0][1][1];
        if(pos+1<i) ans+=f[pos+1][0][0][0];
        // cout<<ans<<"\n";
        // if(pos<i&&f[pos][0][1]) cout<<i<<" "<<pos<<"\n";
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}