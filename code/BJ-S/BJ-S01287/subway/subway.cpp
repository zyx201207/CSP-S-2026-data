#include<bits/stdc++.h>
using namespace std;
int w[int(5.1e5)],vis[int(6e5)];
vector<pair<int, int>> a[510];
int c,n,m,d,q;
struct node{
    vector<pair<int,int>> next;
    bool is_virt=0;
}nodes[int(6e5)];

void build(){
    for (int i = 0; i<n;i++){
        nodes[m+1+i].is_virt=1;
        for (auto p:a[i]){
            int x=p.second;
            if (x==0)continue;
            nodes[m+1+i].next.push_back(p);
            nodes[p.first].next.push_back({m+1+i,x});
        }
        
    }
}

unsigned long bfs(int x, int from, int to, unsigned long ans=0){
    unsigned long rans=-10000;
    auto now = nodes[x];
    //cout << "BFS CALLED x:" << x << " from: " << from << " to: "<<to<<" ans: "<<ans<<endl;

    if (x==to){
        return ans;
    }
    bool can=false;
    for (auto ch:now.next){
        //cout << "CHILDREN: "<< ch.first<<endl;
        // if (!can && now.is_virt){
        //     if (from == ch.first){
        //         can=true;
        //     }
        // }else 
        if (!vis[ch.first]){
            vis[ch.first]++;
            rans=min(rans, (bfs(ch.first, x, to, ans+ch.second)));
        }
}
    return rans;
    
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    cin.sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i<=m;i++){
        cin >> w[i];
    }
    for (int i = 0; i<n;i++){
        int k;cin >> k;
        for (int j = 0; j<k;j++){
            int ai,ti;
            cin >> ai >> ti;
            a[i].push_back({ai,ti});
        }
    }
    build();
    for (int _ = 0; _<q;_++){
        int x,y;
        fill(vis, vis+int(5.9e5), 0);
        cin >> x >> y;
        cout << bfs(x, x, y)+w[x]+w[y]<<'\n';
    }
}