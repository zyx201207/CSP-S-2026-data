#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10,maxm=22*maxn;

int c,n,m,d,p,w,a,t,k,tot[maxn];
int he[maxm],ne[maxm],to[maxm],W[maxm],tet;
int dis[maxm];

void init(){
    for(int i=1;i<=maxm;i++){
        dis[i]=1e9+7;
    }
}

void add_edge(int u,int v,int w){
    tet++;
    ne[tet]=he[u];
    he[u]=tet;
    to[tet]=v;
    W[tet]=w;
    //cout<<"edge added:from "<<u<<" to "<<v<<" weigh:"<<w<<endl;
}

void add_double(int u,int v,int w){
     add_edge(u,v,w);
     add_edge(v,u,w);
}

int main(){
    freopen ("subway.in","r",stdin);
    freopen ("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w;
        add_double((d+2)*i,(d+2)*i+1,w);
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            tot[a]++;
            add_double((d+2)*a+1+tot[a],(m+2)*(d+2)+i,0);
            add_double((d+2)*a+1+tot[a],(d+2)*a+1,t);
        }
    }
    for(int i=1;i<=p;i++){
        init();
        queue<int> q;
        int fi,la;
        cin>>fi>>la;
        q.push((d+2)*fi);
        dis[(d+2)*fi]=0;
        while(!q.empty()){
            int tmp=q.front();
            for(int j=he[tmp];j;j=ne[j]){
                //cout<<"trying "<<tmp<<" to "<<to[j]<<" lenth "<<W[j]<<endl;
                //cout<<dis[tmp]+W[j]<<" "<<dis[to[j]]<<endl;
                if(dis[tmp]+W[j]<dis[to[j]]){
                    dis[to[j]]=dis[tmp]+W[j];
                    //cout<<"shorted "<<to[j]<<" to "<<dis[to[j]]<<endl;
                    q.push(to[j]);
                }
            }
            q.pop();
        }
        cout/*<<i<<":"*/<<dis[(d+2)*la]<<endl;
    }
    return 0;
}
