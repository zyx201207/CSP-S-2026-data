#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int g[MAXN][MAXN];
int c,n,mm,d,q;
struct node{
    int t_kou_to_zhanting;
    int t_zhanting_to_zhantai;
}e[MAXN];//任意一站的进站厅时间和进站台时间
//t_necessary=开始站的kou_to_zhanting + 结束站的kou_to _zhanting;
//每一条边的权=开始边的站台to展厅+结束边的展厅to站台
int dijkstra(int a,int b){
    int dist[MAXN];
    dist[a]=0;
    bool vis[MAXN]={false};
    memset(dist,0x3f,sizeof(dist));
    int u=-1;
    for(int i=1;i<=mm;i++){
        if(!g[a][i]){
            dist[i]=g[a][i];
            vis[i]=true;
        }
    }
    for(int i=1;i<=mm;i++){
        if(dist[i]!=0x3f){
            u=i;
        }
        if(u==-1) continue;
        if(dist[i]==0x3f) continue;
        else{
            for(int j=1;j<=n;i++){
                if(g[u][j]){
                    if(dist[i]>dist[u]+g[u][j]) dist[i]=dist[u]+g[u][j];
                }
            }
        }
        //遍历完不需要换乘的确定点
    }


    return dist[b];

}

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> mm >> d >> q;
    for(int i=1;i<=mm;i++){
        cin >> e[i].t_kou_to_zhanting;
    }

    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        int num[MAXN];
        for(int j=1;j<=k;j++){
            cin >> num[i];
            cin >> e[i].t_zhanting_to_zhantai;
            if(j>=2){
                int k1=num[i-1];
                int k2=num[i];
                g[k1][k2]=e[k1].t_zhanting_to_zhantai+e[k2].t_zhanting_to_zhantai;
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin >> x >> y;
        cout << dijkstra(x,y) << endl;
    }
    return 0;
}
