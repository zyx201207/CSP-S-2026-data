#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int a[505],k[505],dis[505][505];
int c,n,m,q,d;
struct node{
    int id,v;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway3.in","r",stdin);
    freopen("subway3.out","w",stdout);
    cin>> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin>> a[i];
    vector<vector<node>> vc(m+1);
    for(int i=1;i<=n;i++){
        cin>> k[i];
        for(int j=1;j<=k[i];j++){
            int u,w;
            cin>> u >> w;
            node tmp;
            tmp.id=i;
            tmp.v=w;
            vc[u].push_back(tmp);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
            dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int len=vc[i].size();
        if(len>=2){
            for(int j=0;j<len;j++) for(int e=j+1;e<len;e++){
                node xx=vc[i][j],yy=vc[i][e];
                int tmp=xx.v+yy.v;
                dis[xx.id][yy.id]=min(dis[xx.id][yy.id],tmp);
                dis[yy.id][xx.id]=min(dis[yy.id][xx.id],tmp);
            }
        }
    }
    for(int p=1;p<=n;p++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int tmp=dis[i][p]+dis[p][j];
                dis[i][j]=min(dis[i][j],tmp);
                dis[j][i]=min(dis[j][i],tmp);
            }
        }
    }
    for(int z=1;z<=q;z++){
        int x,y;
        cin>> x >> y;
        int ans=0x7f7f7f7f;
        for(auto i:vc[x]) for(auto j:vc[y]){
            int tmp=i.v+j.v;
            tmp+=dis[i.id][j.id];
            ans=min(ans,tmp);
        }
        cout<< ans;
        if(q!=z) cout<< endl;
    }
    return 0;
}
