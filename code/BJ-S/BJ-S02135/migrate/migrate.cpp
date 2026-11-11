#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<ll> x(n+1);
        for (int i=1;i<=n;++i) {
            cin>>x[i];
        }
        ll ans=0;
        for (int s=1;s<=n;++s) {
            vector<int> dis(n+1,INF);
            vector<ll> f(n+1,0);
            dis[s]=0;
            f[s]=1;
            for (int i=s+1;i<=n;++i) {
                int L=lower_bound(x.begin()+1,x.begin()+i,x[i]-d)-x.begin();
                int min_d=INF;
                for (int k=L;k<i;++k) {
                    if (dis[k]!=INF) {
                        min_d=min(min_d,dis[k]+1);
                    }
                }
                dis[i]=min_d;
                if (dis[i]==INF) continue;
                ll sum=0;
                for(int k=L;k<i;++k){
                    if(dis[k]+1==dis[i]){
                        sum+=f[k];
                        if(sum>2) break;
                    }
                }
                f[i]=sum;
                if(f[i]==2) {
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
