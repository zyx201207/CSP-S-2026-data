#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll c,n,m,w[N],d,q;
ll dist[5005][5005],a[N],t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){//m points n edges
        cin>>w[i];
        dist[i][i]=0;
        for(int j=1;j<=m;j++){
            if(j!=i) dist[i][j]=999999999999999999;
        }
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;j++){
            for(int h=1;h<=k;h++){
                dist[a[j]][a[h]]=min(dist[a[j]][a[h]],t[j]+t[h]);
            }
        }
    }
    //floyd
    for(int u=1;u<=m;u++){
        for(int k=1;k<=m;k++){
            for(int v=1;v<=m;v++){
                if(dist[u][v]>dist[u][k]+dist[k][v]) dist[u][v]=dist[u][k]+dist[k][v];
            }
        }
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        cout<<dist[x][y]+w[x]+w[y]<<'\n';
    }
    // \|/
    return 0;
}
