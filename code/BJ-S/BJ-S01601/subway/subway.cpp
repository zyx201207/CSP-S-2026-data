#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int NUM=5e5+5;
const ll MAX=2e9+3;

int n,m,b,e,Q;
int w[NUM],a[NUM],t[NUM];
//priority_queue<pair<int,int>> ro[504];
ll len[504][504];

/*void bellman(int st){
    while(!ro[st].empty()){
        pair<int,int> k=ro[st].top();
        ro[st].pop();
    }
    return;
}*/

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(len,MAX,sizeof(len));

    scanf("%d %d %d %d %d",&b,&n,&m,&e,&Q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
        len[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d %d",&a[i],&t[i]);
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(i!=j){
                    //ro[a[i]].push({a[j],t[i]+t[j]});
                    //ro[a[j]].push({a[i],t[i]+t[j]});
                    len[a[i]][a[j]]=t[i]+t[j];
                    len[a[j]][a[i]]=t[i]+t[j];
                }
            }
        }
    }
    /*for(int i=1;i<=m;i++){
        ro[0].push({i,0});
        ro[i].push({0,0});
    }*/
    //bellman(0);

    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(len[i][k]!=MAX&&len[k][j]!=MAX){
                    len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
                }
            }
        }
    }

    while(Q--){
        scanf("%d %d",&b,&e);
        printf("%lld\n",len[b][e]+w[b]+w[e]);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
