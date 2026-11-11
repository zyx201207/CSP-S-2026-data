#include<bits/stdc++.h>
using namespace std;
int c,q,ans;//number of test and quantity of questions
int n;//quantity of cities
int k;//quantity of labs
vector<int> g[1000006];//available roads between cities
vector<int> choice;//whether we choose it
bool vis[1000006];
unordered_map<int,int> h;
void flood(int a){
    for(int u:g[a]){
        if(!vis[u]) continue;
        if(h.count(u)) continue;
        h[u]++;
        flood(u);
    }
}
int check(){
    int res=0;
    h.clear();
    for(int u:choice){
        if(h.count(u)) continue;
        flood(u);res++;
    }
    return res;
}
int dist[1000006];
int calc(){
    int maxv=0,minv;
    for(int i=1;i<=n;i++){
        memset(dist,0,sizeof dist);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int u:g[cur]){
                if(dist[u]==0){
                    dist[u]=dist[cur]+1;
                    q.push(u);
                }
            }
        }
        minv=0x3f3f3f3f;
        for(int u:choice){
            minv=min(minv,dist[u]);
        }
        maxv=max(maxv,minv);
    }
    return maxv;
}
void choose_do(int cur,int sum){
    if(cur>n) return;
    if(sum==k){
        if(check()<=2){
            ans=min(calc(),ans);
        }
    }
    choose_do(cur+1,sum);
    choice.push_back(cur);
    choose_do(cur+1,sum+1);
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> q;
    while(q--){
        cin >> n >>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << ans << endl;
    }
    return 0;
}
