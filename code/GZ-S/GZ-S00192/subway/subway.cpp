//GZ-S00192 遵义市！第四！中学！ 黄文涛
//Author: ArHanXing
//你好，忘记 dijkstra 怎么写了。
#include<bits/stdc++.h>
#define fri(a,b) for(int i=(a);i<=(b);i++)
#define frm(a,b,m) for(int m=(a);m<=(b);m++)
#define frir(a,b) for(int i=(a);i>=(b);i--)
#define frmr(a,b,m) for(int m=(a);m>=(b);m--)
#define us unsigned
#define xll signed long long
#define ull us long long
#define inf ((int)__INT_MAX__)
#define nul -inf
#define gmax(a,b) a=max(a,b)
#define gmin(a,b) a=min(a,b)
#define MAXN ((xll)5e5)
using namespace std;
//朴素完了，时间复杂度 q(N+M log K)，可能30pts-
int c,n,m,d,Q;
class Node;
class Edge{
public:
    Node* tar;
    int w;

    bool operator<(Edge &other) const{
        return w<other.w;
    }

    Edge(Node* tar,int w):tar(tar),w(w){}
};
class Node{
public:
    vector<Edge> to;
    int idx;

};

array<int,MAXN*2+7> spfa(Node* s){
    queue<Edge> q;
    array<int,MAXN*2+7> dis;
    dis.fill(inf);
    q.push({s,0});
    dis[s->idx]=0;

    while(!q.empty()){
        Edge u=q.front();q.pop();
        //cout<<"--debug-- now header="<<u.tar->idx<<endl;
        for(Edge v:u.tar->to){
            int ndis=dis[u.tar->idx]+v.w;
            if(ndis < dis[v.tar->idx]){
                dis[v.tar->idx]=ndis;
                q.push({v.tar,ndis});
            }
        }
    }
    return dis;
}
Node g[MAXN*2+7];
int additional[MAXN+7];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>Q;
    fri(1,m) cin>>additional[i];
    fri(1,n) g[i].idx=i;
    fri(1,m) g[i+MAXN].idx=i+MAXN;
    fri(1,n){

        int k;
        cin>>k;
        frm(1,k,j){
            int tar,w;
            cin>>tar>>w;
            //地铁站 i 从厅到线 j 的距离
            g[i].to.push_back({&g[tar+MAXN],w});
            g[tar+MAXN].to.push_back({&g[i],w});
            //前一个maxn存线，后一个max存站台
        }
    }

    while(Q--){
        int u,v;
        cin>>u>>v;
        cout<<additional[u]+additional[v]+spfa(&g[u+MAXN])[v+MAXN]<<endl;
    }
    return 0;
}

