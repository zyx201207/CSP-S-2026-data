#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define int long long
#define mp make_pair
using pii = pair<int,int>;
int dFE[500005];
vector<pii > ls[500005];
int l2lmin[505][505];
const int inf = 1e17+7;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, n, m, d, q;cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>dFE[i];
    }
    for(int i = 1;i<=n;i++){
        int k;cin>>k;
        for(int j = 1;j<=k;j++){
            int x, y;cin>>x>>y;
            ls[x].pb(mp(i,y));
        }
    }
    for(int i = 0;i<=n+1;i++){
        for(int j = 0;j<=n+1;j++){
            l2lmin[i][j]=inf;
        }
        l2lmin[i][i] = 0;
    }
    for(int i = 1;i<=m;i++){
        int lss = ls[i].size();
        for(int j = 0;j<lss;j++){
            for(int k = j+1;k<lss;k++){
                int line1 = ls[i][j].first;
                int line2 = ls[i][k].first;
                int len   = ls[i][j].second+ls[i][k].second;
                if(l2lmin[line1][line2]>len){
                    l2lmin[line1][line2]=l2lmin[line2][line1]=len;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++){//midpoint
        for(int j = 1;j<=n;j++){//u
            for(int k = j+1;k<=n;k++){//v
                l2lmin[j][k] = l2lmin[k][j] = min(l2lmin[j][k], l2lmin[j][i]+l2lmin[i][k]);
            }
        }
    }
    for(int i= 1;i<=q;i++){
        int x, y;cin>>x>>y;
        int ansbase = dFE[x]+dFE[y];
        int minn = inf;
        for(pii j:ls[x]){
            for(pii k:ls[y]){
                minn=min(minn, l2lmin[j.first][k.first]+j.second+k.second);
            }
        }
        cout<<ansbase+minn<<endl;
    }
    return 0;
}
