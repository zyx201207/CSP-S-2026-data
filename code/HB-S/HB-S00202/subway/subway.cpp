#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
#define maxm 5005
#define maxn 505
int c,n,m,d,q;
int w[maxm];
int subway[2005];
int t[2005];
struct node{
    int num;
    int sub;
};
int mapp[maxm][maxm];
/*
queue<node> q;
void bfs(int s,int subs,int e){
    q.push({s,subs});
    while(!q.empty()){
        node x=q.front();
        int st=x.num,sb=x.sub;
        for(int i=1;i<=m;i++){
            if(mapp[st][m]!=0){
                return ;
            }
        }
    }
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int p;
            cin>>p>>t[p];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(n==1){
            cout<<w[x]+t[x]+t[y]+w[y]<<'\n';
        }
    }
    return 0;
}
