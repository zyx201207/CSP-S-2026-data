//:( bye
#include<bits/stdc++.h>
using namespace std;
int _,n,m,d,q;
int k[505];//一个站几条线
int bel[505];
int a[505][50005];//第 i 条线路经过的第 j 个地铁站
int t[505][50005];//第 i 条线路经过的第 j 个地铁站站厅走到第 i 条线路的站台需要的时间
int w[505];

int dis[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            bel[a[i][j]]=i;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
    }
    return 0;
}
