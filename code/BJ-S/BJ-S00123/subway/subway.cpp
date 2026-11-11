#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q;
vector<pair<int,long long> > v[500005];
long long w[505][505];
long long d[505][505];
int a[500005];
int len[500005];
long long ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
    for(int i=1;i<=m;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int k;
        int x;
        long long y;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d%lld",&x,&y);
            len[x]++;
            v[x].push_back({i,y});
        }
    }
    /*for(int i=1;i<=m;i++){
        for(int j=0;j<len[i];j++){
            cout<<v[i][j].first<<" "<<v[i][j].second<<"*";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=1e18;
            w[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)d[i][i]=w[i][i]=0;
    long long dist,xx,yy;
    for(int i=1;i<=m;i++){
        for(int l=0;l<len[i];l++){
            for(int r=l+1;r<len[i];r++){
                dist=v[i][l].second+v[i][r].second;
                xx=v[i][l].first;
                yy=v[i][r].first;
                //cout<<xx<<" "<<yy<<" "<<dist<<endl;
                w[xx][yy]=w[yy][xx]=min(w[xx][yy],dist);
                d[xx][yy]=d[yy][xx]=min(d[xx][yy],dist);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
    while(q--){
        ans=1e18;
        int nx,ny;
        scanf("%d%d",&nx,&ny);
        for(int i=0;i<len[nx];i++){
            for(int j=0;j<len[ny];j++){
                ans=min(ans,v[nx][i].second+v[ny][j].second+d[v[nx][i].first][v[ny][j].first]);
            }
        }
        ans+=a[nx]+a[ny];
        printf("%lld\n",ans);
    }
    return 0;
}
