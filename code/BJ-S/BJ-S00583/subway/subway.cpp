#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e18+5;
const int N=5e5+5;
int c,n,m,d,q;//注意区分n和m！！！！！！！！
int w[N];
vector<int> a[505],t[505],p[N],pd[N];
int dis[505][505];//floyd最短距离，记得初始化！！！
int read(){
    int X=0;
    while(1){
        char x=getchar();
        if(isdigit(x)){
            X*=10,X+=(x-'0');
        }
        else return X;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out,","w",stdout);
    //c=read();n=read();m=read();d=read();q=read();
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        for(int j=1;j<=k;++j){
            int x,y;cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            p[x].push_back(i);
            pd[x].push_back(y);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=MAXN;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<a[i].size();++j){
            int to=a[i][j];
            for(int k=0;k<p[to].size();++k){
                int vt=p[to][k];
                if(vt==i) continue;
                dis[i][vt]=min(dis[i][vt],t[i][j]+pd[to][k]);
                dis[vt][i]=dis[i][vt];
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        int ans=MAXN;
        for(int i=0;i<p[x].size();++i){
            for(int j=0;j<p[y].size();++j){
                int res=pd[x][i]+pd[y][j]+dis[p[x][i]][p[y][j]];
                ans=min(ans,res);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
