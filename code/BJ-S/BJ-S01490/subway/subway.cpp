#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
vector<pair<int,int> > A[500010];
int ex[500010];
int dis[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> ex[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int x,val;
            cin >> x >> val;
            A[x].push_back({i,val});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(auto j:A[i]){
            for(auto k:A[i]){
                dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        int ans=1e18;
        for(auto i:A[x]){
            for(auto j:A[y]){
                if(i.first==j.first){
                    ans=min(ans,i.second+j.second+ex[x]+ex[y]);
                }
                else{
                    ans=min(ans,i.second+j.second+dis[i.first][j.first]+ex[x]+ex[y]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
