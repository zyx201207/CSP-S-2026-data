#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=510;
int C,m,n,d,q,w[N],l[M];
long long t[M][M],s[M][M];
vector<int> p[M],c[M];
struct node{
    int id;
    long long dis;
};
vector<node> f[N],r[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&C,&m,&n,&d,&q);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=m;i++){
        scanf("%d",&l[i]);
        for(int j=1;j<=l[i];j++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i].push_back(x);
            c[i].push_back(y);
            f[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(i!=j)t[i][j]=1e17;
    for(int i=1;i<=n;i++){
        for(int j=0;j<f[i].size();j++){
            for(int k=0;k<f[i].size();k++){
                t[f[i][j].id][f[i][k].id]=min(t[f[i][j].id][f[i][k].id],f[i][j].dis+f[i][k].dis);
            }
        }
    }

    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=t[i][j];
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
    for(int i=1;i<=q;i++){
        int x,y;
        long long ans=1e18;
        scanf("%d%d",&x,&y);
        for(int j=0;j<f[x].size();j++){
            for(int k=0;k<f[y].size();k++){
                ans=min(ans,s[f[x][j].id][f[y][k].id]+f[x][j].dis+f[y][k].dis);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
