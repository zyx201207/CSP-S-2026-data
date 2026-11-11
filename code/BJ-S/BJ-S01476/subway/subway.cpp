#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],dist[4*500005];
struct Node{
    int num,x;
    int time;
    bool operator <(const Node &a) const{
        return time>a.time;
    }
};
vector<Node> e[4*500005];
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway1.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int last_a=-1;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            e[i*m+a].push_back({0,a,t});
            e[a].push_back({i,i*m+a,t});
            if(last_a){
                e[i*m+a].push_back({i,i*m+last_a,0});
                e[i*m+last_a].push_back({i,i*m+a,0});
            }
            last_a=a;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        for(int i=1;i<=m*(n+1);i++){
            dist[i]=1e9;
        }
        dist[x]=0;
        priority_queue<Node> q;
        q.push({0,x,0});
        while(!q.empty()){
            Node now=q.top();
            q.pop();
            for(int i=0;i<e[now.x+now.num*m].size();i++){
                cout<<1;
                Node curr=e[now.x+now.num*m][i];
                cout<<dist[curr.x+curr.num*m]<<endl;
                if(now.time + curr.time<=dist[curr.x+curr.num*m]){
                    dist[curr.x+curr.num*m]=now.time + curr.time;
                    cout<<dist[curr.x+curr.num*m]<<endl;
                    q.push({curr.num,curr.x,dist[curr.x+curr.num*m]});
                }
            }
        }
        int ans=1e9;
        for(int i=1;i<=m*(n+1);i++){
            cout<<dist[i]<<' ';
        }
        for(int i=0;i<=n;i++){
            ans=min(ans,dist[m*i+y]);
        }
        cout<<endl;
        cout<<ans+w[x]+w[y]<<endl;
    }
}
