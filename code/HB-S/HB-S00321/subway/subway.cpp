#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[505][505],toneed[500005],hdis[500005][25],hdisz[500005][25];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        cin>>toneed[i];
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        int k;
        cin>>k;
        while(k--){
            int a,b;
            cin>>a>>b;
            hdis[a][++hdis[a][0]]=b;
            hdisz[a][hdis[a][0]]=i;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=hdis[i][0];j++){
            for(int k=1;k<j;k++){
                dis[hdisz[i][j]][hdisz[i][k]]=min(dis[hdisz[i][j]][hdisz[i][k]],hdis[i][j]+hdis[i][k]);
                dis[hdisz[i][k]][hdisz[i][j]]=min(dis[hdisz[i][k]][hdisz[i][j]],hdis[i][j]+hdis[i][k]);
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
        int a,b;
        cin>>a>>b;
        int sum=toneed[a]+toneed[b],ans=1000000000000000000;
        for(int i=1;i<=hdis[a][0];i++){
            for(int j=1;j<=hdis[b][0];j++){
                ans=min(ans,hdis[a][i]+hdis[b][j]+dis[hdisz[a][i]][hdisz[b][j]]);
            }
        }
        cout<<sum+ans<<"\n";
    }
    return 0;
}
