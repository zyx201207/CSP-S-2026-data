#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int val,a,b;
    bool operator < (const Node other)const{
        return val>other.val;
    };
};

int c,n,m,d,q;
vector <int> w;
vector <vector <pair <int,int> > > Map;

namespace map2{
    vector <map <int,int> > Map;
}

vector <int> dij(int s,vector <int> input){
    vector <int> vis(n+m+1);
    vector <int> dis(n+m+1);
    priority_queue <Node> queue;

    for(int i=1;i<input.size();i++){
        if(input[i]){
            vis[m+i]=true;
            dis[m+i]=input[i];
        }
    }

    queue.push({0,0,s});
    while(queue.size()){
        int dist=queue.top().val;
        int ids=queue.top().a;
        int id=queue.top().b;
        queue.pop();

        if(vis[id])
            continue;

        vis[id]=true;
        dis[id]=dis[ids]+dist;

        for(auto v : Map[id])
            if(!vis[v.first])
                queue.push({v.second,id,v.first});
    }

    return dis;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    
    Map.resize(n+m+1);

    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        w.push_back(a);
    }

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            Map[m+i].push_back({a,t});
            Map[a].push_back({m+i,t});
        }
    }

    map2::Map.resize(n+1);
    for(int i=m+1;i<=m+n;i++){
        vector <int> in;
        in.push_back(0);
        for(int j=1;j<i-m;j++)
            in.push_back(map2::Map[j][i-m]);
            
        vector <int> dis=dij(i,in);
        for(int j=m+1;j<=m+n;j++)
            map2::Map[i-m][j-m]=dis[j];
    }

    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;

        int ans=INT_MAX;
        for(auto v : Map[s])
            for(auto w : Map[e])
                ans=min(ans,::w[s-1]+::w[e-1]+v.second+w.second+map2::Map[v.first-m][w.first-m]);    

        cout<<ans<<"\n";
    }

    return 0;
}