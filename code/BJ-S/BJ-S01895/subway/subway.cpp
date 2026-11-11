#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+10;
const int maxn=510;
const int maxq=1e5+10;
int c, n, m, d, q;
int w[maxm];
int k[maxn];
int a[maxn][maxm], t[maxn][maxm];
int nxt[maxm][maxn];
int sear(int tar, int path)
{
    int l=1, r=k[path];
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[path][mid]==tar){
            return mid;
        }else if(a[path][mid]<tar)
        {
            l=mid;
        }else r=mid;
    }
}
void dfs(int i, int sum, int path, int y, int ans)
{
     if(i==y){
        sum+=t[path][sear(y, path)];
        ans=max(ans, sum);
        return ;
    }
    for(int j=1; j<=d; ++j){
        if(nxt[i][j]==0) return ;
        if(j==path) dfs(nxt[i][j], sum, path, y, ans);
        dfs(nxt[i][j], sum+(t[path][sear(i, path)]+t[j][sear(i, j)]), j, y, ans);
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int x=0, y=0, ans=0;
    cin >>c >>n >>m >>d >>q;
    for(int i=1; i<=m; ++i) cin >>w[i];
    for(int i=1; i<=n; ++i){
        cin >>k[i];
        for(int j=1; j<=k[i]; ++j){
            cin >>a[i][j] >>t[i][j];
            nxt[a[i][j-1]][i]=a[i][j];
        }
    }
    while(q--){
        cin >>x >>y;
        int ans=w[x]+w[y];
        for(int path=1; path<=d; ++path){
            if(nxt[x][path]!=0) dfs(x, ans+t[path][sear(x, path)], path, y, ans);
        }
        cout <<ans <<"\n";
    }
    return 0;
}