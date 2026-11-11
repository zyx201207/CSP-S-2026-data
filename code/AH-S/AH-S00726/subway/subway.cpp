#include<bits/stdc++.h>
using namespace std;

struct edge{
    int to,w;
};

int c,n,m,d,q,st,ed,v[500005],value[500005][505];
int dis,mint=0x3f3f3f3f;
bool bl[500005];
vector <int> g[505];
vector <edge> h[500005];

void dfs(int x,int e,int dis){
    if(x==ed){
        dis+=value[x][e];
        mint=min(mint,dis+v[st]+v[ed]);
        return ;
    }
    for(int i=0;i<h[x].size();i++){
        if(bl[h[x][i].to] && e!=0) continue;
        if(e==0){
            dis+=value[x][h[x][i].w];
            bl[h[x][i].to]=1;
            dfs(h[x][i].to,h[x][i].w,dis);
            bl[h[x][i].to]=0;

        }else if(h[x][i].w!=e){
            dis+=value[x][h[x][i].w]+value[x][e];
            bl[h[x][i].to]=1;
            dfs(h[x][i].to,h[x][i].w,dis);
            bl[h[x][i].to]=0;

        }else{
            bl[h[x][i].to]=1;
            dfs(h[x][i].to,h[x][i].w,dis);
            bl[h[x][i].to]=0;
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>v[i];
    }
    for(int i=1,t;i<=n;i++){
        cin>>t;
        int tmp=0;
        for(int j=1,x,y;j<=t;j++){
            cin>>x>>y;
            value[x][i]=y;
            if(j!=1 && tmp!=0){
                h[tmp].push_back((edge){x,i});
                h[x].push_back((edge){tmp,i});
            }
            tmp=x;
        }
    }
    for(int i=1;i<=q;i++){
        dis=0;
        memset(bl,0,sizeof(bl));
        cin>>st>>ed;
        bl[st]=1;
        dfs(st,0,0);
        cout<<mint<<"\n";
    }
    return 0;
}
