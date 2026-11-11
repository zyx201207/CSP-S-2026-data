#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>

#define int long long

using namespace std;

const int N=4e6+5;

typedef pair<int,int> PII;

int e[N],idx,h[N],w[N],ne[N];
int c,n,m,d,q;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dist[N];
bool st[N];
int dijkstra(int s,int ended){
    priority_queue<PII,vector<PII>,greater<PII>> q;
    memset(dist,0x3f,sizeof(dist));
    memset(st,false,sizeof(st));
    dist[s]=0;
    q.push({0,s});
    while(q.size()){
        int u=q.top().second;
        q.pop();
        if(st[u])continue;
        st[u]=true;

        for(int i=h[u];~i;i=ne[i]){
            int v=e[i];
            if(dist[v]>dist[u]+w[i]){
                dist[v]=dist[u]+w[i];
                q.push({dist[v],v});
            }
        }
    }
    return dist[ended];
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(h,-1,sizeof(h));

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        int w;
        cin>>w;
        add(i,i+m+1,w);
        add(i+m+1,i,w);
    }

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int id,w;
            cin>>id>>w;
            add(i+m+m+d+1,id+m+1,w);
            add(id+m+1,i+m+m+d+1,w);

        }
    }

    for(int i=1;i<=q;i++){
        int sta,eds;
        cin>>sta>>eds;
        cout<<dijkstra(sta,eds)<<endl;
    }

    return 0;
}


