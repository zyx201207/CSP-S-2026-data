#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii>e[3*N];//1~m kou m+1~m+m ting m+m+1~m+m+n ditie
priority_queue<pii,vector<pii>,greater<pii> >pq;
ll dis[3*N];
bool vis[3*N];
ll dd[505][505];
vector<pii> a[N];
ll w[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1,x;i<=m;i++)cin>>w[i];
    memset(dd,0x3f,sizeof dd);
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(ll j=1,x,y;j<=k;j++){
            cin>>x>>y;
            for(auto l:a[x]){
                if(l.first==x)continue;
                dd[i][l.first]=min(dd[i][l.first],l.second+y);
            }
            a[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dd[i][j]=min(dd[i][j],dd[j][i]);
            dd[j][i]=min(dd[i][j],dd[j][i]);
            if(i==j)dd[i][j]=dd[j][i]=0;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&dd[i][k]<0x3f3f3f3f3f3f3f3f&&dd[j][k]<0x3f3f3f3f3f3f3f3f);
                dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto i:a[x]){
            for(auto j:a[y]){
                ans=min(ans,i.second+j.second+dd[i.first][j.first]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
