#include<bits/stdc++.h>
using namespace std;
struct node{
    int road,cur,ans;
};
int c,n,m,d,q;
int w[300000];
int k[1000];
int a[505][505],t[505][505];
int minans=INT_MAX;
void bfs(int road,int cur,int purpose){
    queue<node> q;
    q.push({road,cur,0});
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(cur.cur==purpose){
            minans=min(minans,cur.ans);
            continue;
        }

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        minans=INT_MAX;
        int x,y;
        cin>>x>>y;
        bool b=0;
        //minans+=w[x]+w[y];
        for(int j=1;j<=n;j++){
            for(int h=1;h<=k[j];h++){
                if(a[j][h]==x){
                    bfs(j,x,y);
                    b=1;
                    break;
                }
            }
            if(b)break;
        }
    }
    return 0;
}
