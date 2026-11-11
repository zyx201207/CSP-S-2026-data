#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=5e2+10;
const int maxm=5e5+10;
const int maxq=1e5+10;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
int c,n,m,d,q;
vector<pii> a[maxm],g[maxm];
int w[maxm],k[maxn],res[maxn][maxn],h[maxn][maxm];
void solve1(){
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back({0,0});
        pii t;
        for(int j=1;j<=k[i];j++){
            cin>>t.first>>t.second;
            a[i].push_back(t);
            g[t.first].push_back({i,t.second});
        }
        sort(a[i].begin(),a[i].end());
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            res[i][j]=inf;
            int l=1,r=1;
            while(l<=k[i] && r<=k[j]){
                if(a[i][l].first==a[j][r].first){
                    res[i][j]=min(res[i][j],a[i][l].second+a[j][r].second);
                    l++,r++;
                }
                else if(a[i][l].first>a[j][r].first){
                    r++;
                }
                else{
                    l++;
                }
            }
        }
    }
    for(int o=1;o<=n;o++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    res[i][j]=min(res[i][j],res[i][o]+res[o][j]);
                }
            }
        }
    }
    while(q--){
        int x,y,ans=inf;
        cin>>x>>y;
        for(pii i:g[x]){
            for(pii j:g[y]){
                ans=min(ans,res[i.first][j.first]+i.second+j.second);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c<=25){
        solve1();
    }
    return 0;
}
