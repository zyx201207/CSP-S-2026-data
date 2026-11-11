#include<bits/stdc++.h>
#define MAXM 510
#define MAXN 110
using namespace std;
int c,n,m,d,q;
int dis[MAXM][MAXM];
int w[MAXM],k[MAXM],a[MAXN][MAXN],t[MAXN][MAXN],x[10010],y[10010];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i < m;i++){
        cin>>w[i];
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            dis[i][j]=0x3f3f3f3f;
        }
    }
    for(int i = 0;i < n;i++){
        cin>>k[i];
        for(int j = 0;j < k[i];i++){
            
            cin>>a[i][j]>>t[i][j];
            
        }
        for(int j = 0;j < k[i]-1;i++){
            dis[a[i][j]][a[i][j+1]]=t[i][j]+t[i][j+1];
        }

    }
    
    for(int i = 1;i <= m;i ++){
        for(int j = 1;j<=m;j++){
            for(int k =1;k<=m;k++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i = 0;i < q;i++){
        cin>>x[i]>>y[i];
        cout<<dis[x[i]][y[i]]+w[x[i]]+w[y[i]]<<endl;
    }
    return 0;
}