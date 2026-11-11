#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500005,inf=2e18;
int id,n,m,d,q,w[M],dis[N][N];
struct node{
    int v,w;
};
vector<node>v[M];
int solve(int a,int b){
    int res=inf;
    for(node x:v[a]){
        for(node y:v[b]){
            res=min(res,x.w+dis[x.v][y.v]+y.w);
        }
    }
    return res;
}
int read(){int a=0,b=1;char c;for(;!isdigit(c);c=getchar()){if(c=='-'){b=-1;}}for(;isdigit(c);c=getchar()){a=a*10+c-'0';}return a*b;}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    id=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int a=read(),t=read();
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=inf;
            if(i==j){
                dis[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(node x:v[i]){
            for(node y:v[i]){
                dis[x.v][y.v]=min(dis[x.v][y.v],x.w+y.w);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(node j:v[i]){
            cout<<j.v<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            cout<<i<<"->"<<j<<": "<<dis[i][j]<<endl;
        }
    }
    */
    while(q--){
        int x=read(),y=read();
        cout<<solve(x,y)+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
/*
rp++
rp++
rp++
//freopen("subway","r",stdin)
wo yao shang mi huo xing wei da shang
3:30 AC T1 T2
ran hou da nao kong bai bai lan
*/
