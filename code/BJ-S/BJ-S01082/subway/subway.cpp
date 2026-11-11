#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int c,n,m,d,q;
int w[N],k[N];
int a,t;
vector<pair<int,int> > e[N];
struct T{
    int u,v,w;
}ee[N];
int tot;
int ds[2005][2005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    if(c<=8){
            for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            e[a].push_back({t,m+i});
            e[m+i].push_back({t,a});
            ee[++tot]={a,m+i,t};
            ee[++tot]={m+i,a,t};
        }
    }
    memset(ds,0x3f,sizeof(ds));
    for(int i=1;i<=m+n;i++){
        ds[i][i]=0;
    }
    for(int l=1;l<=tot;l++){
        for(int i=1;i<=m+n;i++){
            for(int j=i+1;j<=m+n;j++){
                ds[i][j]=min(ds[i][j],ds[i][ee[l].u]+ds[j][ee[l].v]+ee[l].w);
                ds[j][i]=ds[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+ds[u][v]<<'\n';
    }
    }
    else if(9<=c&&c<=11){
        for(int i=1;i<=n;i++){
        cin>>k[i];
        cin>>a>>t;
        int aa=a,tt=t;
        if(k[i]==2){
        cin>>a>>t;
        e[a].push_back({aa,t+tt});
        e[aa].push_back({a,t+tt});
        ee[++tot]={a,aa,t+tt};
        ee[++tot]={aa,a,t+tt};
        }
        }
        memset(ds,0x3f,sizeof(ds));
    for(int i=1;i<=m;i++){
        ds[i][i]=0;
    }
    for(int l=1;l<=tot;l++){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                ds[i][j]=min(ds[i][j],ds[i][ee[l].u]+ds[j][ee[l].v]+ee[l].w);
                ds[j][i]=ds[i][j];
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+ds[u][v]<<'\n';
    }
    }

    return 0;
}
