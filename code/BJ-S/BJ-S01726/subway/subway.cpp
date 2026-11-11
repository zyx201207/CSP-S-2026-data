#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,w[50005],t[505][50005],numx[505],a[505][50005],z[50005][505],numz[50005],book[50005],bookl[505],maxx=INT_MAX,ans;
void dfs(int p,int line,int time){
    //cout<<p<<" "<<line<<" "<<time<<endl;
    if(p==y&&time<maxx){
        maxx=time;
        ans=time+t[line][p];
    }
    if(time>maxx)return ;
    for(int k=1;k<=numx[line];k++){
        if(a[line][k]!=p&&book[a[line][k]]==0){
            book[a[line][k]]=1;
            dfs(a[line][k],line,time);
            book[a[line][k]]=0;
        }
    }
    for(int k=1;k<=numz[p];k++){
        if(z[p][k]!=line&&bookl[z[p][k]]==0){
            bookl[z[p][k]]=1;
            dfs(p,z[p][k],time+t[line][p]+t[z[p][k]][p]);
            bookl[z[p][k]]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>numx[i];//第i条线路经过的站点数
        for(int j=1;j<=numx[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];//线路i的第j个站点与换乘时间
            numz[a[i][j]]++;//经过站 a[i][j]的路线条数
            z[a[i][j]][numz[a[i][j]]]=i;//站 a[i][j] 的第 numz[a[i][j]] 条线
        }
    }
    for(int i=1;i<=q;i++){
        maxx=INT_MAX;
        cin>>x>>y;
        for(int j=1;j<=numz[x];j++){//走哪条线
            for(int k=1;k<=m;k++)book[k]=0;// 初始所有站点都未经过
            for(int k=1;k<=n;k++)bookl[k]=0;// 初始所有路线都未经过
            book[x]=1;
            dfs(x,z[i][j],t[z[i][j]][x]);
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
