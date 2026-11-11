#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,qq,w[500010];ll q[510][510];
const ll inf=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int> >v[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=n+2;i++)for(int j=1;j<=n+2;j++)q[i][j]=inf;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x:v[i]){
            for(auto y:v[i]){
                int a=x.first,b=x.second,c=y.first,d=y.second;
                q[a][c]=min(q[a][c],(ll)b+d);
                q[c][a]=min(q[c][a],(ll)b+d);
            }
        }
    }
    for(int i=1;i<=n;i++){
        q[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                q[i][j]=min(q[i][j],q[i][k]+q[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<q[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    while(qq--){
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        for(auto a:v[x]){
            for(auto b:v[y]){
                int v=a.first,u=b.first,aw=a.second,bw=b.second;
                ans=min(ans,aw+bw+q[u][v]);

            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}

