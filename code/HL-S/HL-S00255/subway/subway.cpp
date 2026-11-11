#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,u,v;
long long ans;
struct stations{
    int dr_hl;
    vector<int> a,t;
}st[100005];
vector<int> sub[100005];
long long dis[100005];
void research(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({dis[u],u});
    while(!q.empty()){
        auto cur=q.top();
        q.pop();
        if(dis[cur.second]<cur.first) continue;
        for(int i=0;i<st[cur.second].a.size();i++){
            int cost=st[cur.second].t[i];
            int w=st[cur.second].a[i];
            for(int j=0;j<sub[w].size();j++){
                if(dis[sub[w][j]]>dis[cur.second]+cost+st[sub[w][j]].t[j]){
                    dis[sub[w][j]]=dis[cur.second]+cost+st[sub[w][j]].t[j];
                    q.push({dis[sub[w][j]],sub[w][j]});
                }
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> st[i].dr_hl;
    for(int i=1;i<=n;i++){
        int k;cin >> k;
        for(int j=1;j<=k;j++){
            int x,y;cin >> x >> y;
            st[x].a.push_back(i);
            sub[i].push_back(x);
            st[i].t.push_back(y);
        }
    }
    while(q--){
        cin >> u >> v;
        memset(dis,0x7f7f7f7f,sizeof dis);
        ans=st[u].dr_hl+st[v].dr_hl;
        dis[u]=0;
        research();
        cout << ans+dis[v] << "\n";
    }
    return 0;
}






