#include<iostream>
using namespace std;

int c,n,m,d,q;
int w[500001],k[500001],a[500001][20001];
int h[500001][20001];
int dfs(int cnt,int c,int d,int y){
    cnt+=h[c][d];
    if(a[c][d]==y) return cnt;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k[i];j++){
            for(int k=1;k<=i;k++){
                if(a[i+k][j]==a[i][j]) dfs(cnt,i,j,y);
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++) cin >> a[i][j] >> h[i][j];
    }
    int minn=1e7,cnt=0;
    while(q--){
        int x,y;
        cin >> x >> y;
        int ans=0;
        ans+=w[x];
        ans+=w[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==x)dfs(cnt,i,j,y);
                minn=min(minn,cnt);
            }
        }
    }
    cout << minn;

    return 0;
}
