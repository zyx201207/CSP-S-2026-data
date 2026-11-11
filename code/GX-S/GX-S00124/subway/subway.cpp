#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>> deg1[505];
vector<int> line1[500005];
long long map1[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++){scanf("%d",&w[i]);}
    for(int i = 1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j<=k;j++){
            pair<int,int>node;
            scanf("%d %d",&node.first,&node.second);
            deg1[i].push_back(node);
            line1[node.first].push_back(i);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            map1[i][j]=1e18;
            if(i==j)map1[i][j]=0;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<deg1[i].size();j++){
            int nb=deg1[i][j].first;
            for(int v : line1[nb]){
                if(v==i)continue;
                int a=0;
                while(deg1[v][a].first!=nb)a++;
                map1[i][v]=min(map1[i][v],(long long)(deg1[i][j].second+deg1[v][a].second));
                map1[v][i]=map1[i][v];
            }
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                map1[i][j]=min(map1[i][j],map1[i][k]+map1[k][j]);
            }
        }
    }
    for(int i = 0;i<q;i++){
        long long x,y,minl=1e18;
        scanf("%lld %lld",&x,&y);
        for(int u : line1[x]){
            for(int v : line1[y]){
                int a=0,b=0;
                while(deg1[u][a].first!=x)a++;
                while(deg1[v][b].first!=y)b++;
                minl=min(minl,(long long)map1[u][v]+deg1[u][a].second+deg1[v][b].second);
            }
        }
        minl+=w[x]+w[y];
        cout<<minl<<endl;
    }
}
