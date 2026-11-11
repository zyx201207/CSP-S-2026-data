#include<bits/stdc++.h>

using namespace std;
const int maxm=5e5+10;
const int maxn=510;
int c,n,m,d,q;//c:测试点编号、n:地铁线路数、m:地铁站数、d:每个地铁站最多被几条线路经过,q:出行计划数
int w[maxm],a[maxn][5010],t[maxn][5010],k[maxn];//w[i]:从i个地铁站的地铁口走到站厅需要的时间,k[i]:第 i 条线路经过的地铁站数,a[i][j]:第 i 条线路经过的第 j 个地铁站,t[i][j]从a[i][j]地铁站的站厅走到第 i 条线路的站台需要的时间
struct T{
    int data,ln;
};
vector<T> x;
int is[maxn][maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    /*memset(is,10000000,sizeof(is));
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            for(int aa=1;aa<=k[i];aa++){
                for(int bb=1;bb<=k[j];bb++){
                    if(a[i][aa]==a[j][bb]){
                        is[i][j]=min(is[i][j],t[i][a[i][aa]]+t[j][a[j][bb]]);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)cout<<is[i][j]<<' ';
        cout<<'\n';
    }*/
    while(q--){
        int x,y;
        cin>>x>>y;
        if(c==20 || c==21){
            if(n==1){
                int j1,j2;
                for(int i=1;i<=k[1];i++){
                    if(a[1][i]==x)j1=i;
                    if(a[1][i]==y)j2=i;
                }
                cout<<w[x]+t[1][a[1][j1]]+w[y]+t[1][a[1][j2]]<<'\n';
            }else if(n==2){
                int j1=-1,j2=-1;
                for(int i=1;i<=k[1];i++){
                    if(a[1][i]==x)j1=i;
                    if(a[1][i]==y)j2=i;
                }
                if(j1 && j2)cout<<w[x]+t[1][a[1][j1]]+w[y]+t[1][a[1][j2]]<<'\n';
                j1=-1,j2=-1;
                for(int i=1;i<=k[2];i++){
                    if(a[2][i]==x)j1=i;
                    if(a[2][i]==y)j2=i;
                }
                if(j1 && j2)cout<<w[x]+t[2][a[2][j1]]+w[y]+t[2][a[2][j2]]<<'\n';
            }
        }
    }
    return 0;
}
