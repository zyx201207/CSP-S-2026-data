#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[500005],k[505],a[500005],t[500005],bb[505][505];
struct nd{
    int a,b;
};
vector<nd> v1[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            bb[i][j]=1e18;
        }
        bb[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[j] >> t[j];
            v1[a[j]].push_back(nd{i,t[j]});

        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<v1[i].size();j++){
            for(int k=0;k<j;k++){
                bb[v1[i][j].a][v1[i][k].a]=min(bb[v1[i][j].a][v1[i][k].a],v1[i][j].b+v1[i][k].b);
                bb[v1[i][k].a][v1[i][j].a]=min(bb[v1[i][k].a][v1[i][j].a],v1[i][j].b+v1[i][k].b);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                bb[i][j]=min(bb[i][j],bb[i][k]+bb[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin >> x >> y;
        int ans=1e18;
        for(int j=0;j<v1[x].size();j++){
            for(int k=0;k<v1[y].size();k++){
                nd xx=v1[x][j],yy=v1[y][k];
                int ls=bb[xx.a][yy.a]+xx.b+yy.b;
                ans=min(ans,ls);
            }
        }
        ans=ans+w[x]+w[y];
        cout << ans << "\n";
    }
    return 0;
}
