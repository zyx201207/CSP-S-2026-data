#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int c,t;
long long n,d;
long long a[N];
long long cnt[N][N];
long long mi[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        memset(mi,0x3f,sizeof(mi));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;++i){
            cin>>a[i];
            mi[i][i]=0;
            cnt[i][i]=1;
        }
        for(int u=1;u<=n;++u){
            for(int v=u+1;v<=n && a[v]-a[u]<=2*d;++v){
                for(int s=1;s<=min(a[v]-a[u],d);++s){
                    if(mi[u][v-s]+1 < mi[u][v]){
                        mi[u][v] = mi[u][v-s]+1;
                        cnt[u][v] = cnt[u][v-s];
                    } else if(mi[u][v-s]+1 == mi[u][v]){
                        cnt[u][v] += cnt[u][v-s];
                    }
                }
                if(cnt[u][v]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
