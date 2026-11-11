#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
int n,m,c,k,d,q,t,a;
long long w[M],f[N][N],ans;
struct T{
    int t,w;
};
vector<T>sub[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            sub[a].push_back({i,t});
        }
        for(int j=1;j<=n;j++)f[i][j]=0x3f3f3f3f3f3f3f3f;
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        t=sub[i].size();
        for(int x=0;x<t;x++)
            for(int y=x+1;y<t;y++)
                if(f[sub[i][x].t][sub[i][y].t]>sub[i][x].w+sub[i][y].w)
                    f[sub[i][x].t][sub[i][y].t]=f[sub[i][y].t][sub[i][x].t]=sub[i][x].w+sub[i][y].w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(f[i][j]>f[i][k]+f[k][j])
                    f[i][j]=f[i][k]+f[k][j];
    while(q--){
        cin>>a>>c;
        ans=0x3f3f3f3f3f3f3f3f;
        for(auto x:sub[a])
            for(auto y:sub[c])
                if(ans>f[x.t][y.t]+x.w+y.w)
                    ans=f[x.t][y.t]+x.w+y.w;
        cout<<ans+w[a]+w[c]<<'\n';
    }
    return 0;
}