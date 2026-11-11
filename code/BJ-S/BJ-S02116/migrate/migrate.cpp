#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define int long long
#define mp make_pair
using pii = pair<int, int>;
const int inf = 1e17+7;
namespace dp{
    int a[200005];
    int rcover[200005];
    int lcover[200005];
    pii dpa[200005];
    void solve(){
        int ans = 0;
        int n, d;
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            dpa[i]=mp(inf, 0);
        }
        for(int i = 1;i<=n;i++){
            rcover[i]=upper_bound(a+1, a+n+1, a[i]+d)-a-1;
            lcover[i]=lower_bound(a+1, a+n+1, a[i]-d)-a;
        }
        for(int beg = 1;beg<=n;beg++){
            dpa[beg]=mp(0, 1);
            for(int i = beg+1;i<=rcover[beg];i++){
                dpa[i]=mp(1, 1);
            }
            for(int i = rcover[beg]+1;i<=n;i++){
                int minn = inf;
                for(int j = lcover[i];j<=i-1;j++){
                    minn=min(dpa[j].first,minn);
                }
                int cnt = 0;
                for(int j = lcover[i];j<=i-1;j++){
                    if(dpa[j].first==minn){
                        cnt+=dpa[j].second;
                    }
                }
                if(cnt==2)++ans;
                dpa[i]=mp(minn+1, cnt);
            }
        }
        cout<<ans<<endl;
        return;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, t;cin>>c>>t;
    while(t--){
        dp::solve();
    }
    return 0;
}
