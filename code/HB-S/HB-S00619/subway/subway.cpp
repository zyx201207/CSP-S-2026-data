#include<bits/stdc++.h>
using namespace std;
const int MAXM=100;
const int MAXN=100;
const int MAXSK=1005;
int w[MAXM];
vector<int> a[MAXN];
vector<int> t[MAXN];
int floyd[MAXM*2*MAXN][MAXM*2*MAXN];  //~1~m di'tie'kou~, 1~m zhan'ting, m+1~2m zhan'tai
void addEdge(int x,int y,int len){
    floyd[x][y]=len;
    floyd[y][x]=len;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(floyd,0x3f3f3f3f,sizeof(floyd));
    for(int i=1;i<=m;i++){
        cin>>w[i];
        // addEdge(i,i+m,w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int ai,ti;
            cin>>ai>>ti;
            a[i].push_back(ai);
            t[i].push_back(ti);
        }
        for(int j=0;j<k;j++){
            addEdge(m+a[i][j]+i,m+a[i][(j+1)%k],0);
            addEdge(a[i][j],m+a[i][j]+i,t[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        floyd[i][i]=0;
    }
    for(int k=1;k<=m*2;k++){
        for(int i=1;i<=m*2;i++){
            for(int j=1;j<=m*2;j++){
                if(floyd[i][j]>floyd[i][k]+floyd[k][j]){
                    floyd[i][j]=floyd[i][k]+floyd[k][j];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<floyd[x][y]+w[x]+w[y]<<endl;
    }
}