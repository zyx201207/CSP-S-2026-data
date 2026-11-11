#include <bits/stdc++.h>
using namespace std;
struct node{
    long long x,y,id;
}qu[100008];
int n,m,q,C,d,k;
long long w[500008],t[608][608],f[1008][1008],x,y,T,ans[100008],len[600008],ll[1008][1008],a[20];
vector<pair<int,long long> >g[1008];
bool is[1008][1008];
bool cmp(node x,node y){
    return x.x<y.y;
}
void djs(int s){
    priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >p;
    f[s][s]=0;
    p.push({0,s});
    while(!p.empty()){
        int x=p.top().second;
        p.pop();
        if(is[s][x]){
            continue;
        }
        is[s][x]=1;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i].first;
            long long z=g[x][i].second;
            if(z+f[s][x]<f[s][y]){
                f[s][y]=z+f[s][x];
                p.push({f[s][y],y});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    if(C<=8&&C>=1){
        for(int i=1;i<=m;i++){
            cin>>w[i];
            //cout<<w[i]<<endl;
        }
        memset(f,0x3f,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>x>>y;
                f[x][m+i]=f[m+i][x]=y;
            }
        }
        for(int i=1;i<=n+m;i++){
            f[i][i]=0;
        }
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                for(int k=1;k<=n+m;k++){
                    if(f[i][k]+f[k][j]<f[i][j]){
                        f[i][j]=f[j][i]=f[i][k]+f[k][j];
                        //<<i<<" "<<j<<" "<<f[i][j]<<" "<<k<<" "<<f[i][k]<<" "<<f[k][j]<<endl;
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            //cout<<f[x][y]<<endl;
            cout<<(f[x][y]+w[x]+w[y])<<endl;
        }
    }
    if(C>=9&&C<=11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=f[j][i]=1e18;
                ll[i][j]=ll[j][i]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>k;
            long long sum=0;
            for(int j=1;j<=k;j++){
                cin>>a[j]>>y;
                sum+=y;
            }
            if(k==2){
                ll[a[2]][a[1]]=ll[a[1]][a[2]]=min(ll[a[1]][a[2]],sum);
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(ll[i][j]!=1e18){
                    g[i].push_back({j,ll[i][j]});
                }
            }
        }
        for(int i=1;i<=m;i++){
            djs(i);
        }
        for(int i=1;i<=q;i++){
            cin>>x>>y;
            cout<<(f[x][y]+w[x]+w[y])<<endl;
        }
    }
    return 0;
}
