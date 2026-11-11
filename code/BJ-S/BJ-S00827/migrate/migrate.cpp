#include <bits/stdc++.h>
// #define int long long
using namespace std;
vector<int>g[5005];
vector<int> a;
int n,d;
bool vis[5005];
int bfs(int st,int ed){
    bool f=0;
    int cnt=0,ccnt=8e8;
    queue<pair<int,int>> q;
    map<int,int> mp;
    q.push({st,0});
    while(!q.empty()){
        auto h=q.front();q.pop();
        // vis[h.first]=1;
        if(h.first==ed){
            // cout<<st<<" "<<ed<<" "<<h.second<<"\n";
            
            ccnt=min(ccnt,h.second);
            mp[h.second]++;
            break;
        }
        // cout<<"D";
        for(auto p:g[h.first]) if(p<=ed) q.push({p,h.second+1});
        // vis[h.first]=0;
    }
    return mp[ccnt];
}
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            int dst=a[i]-a[j];
            if(dst<=d) {g[j].push_back(i);
            // cout<<i<<" "<<j<<endl;
            }
        }
        reverse(g[i].begin(),g[i].end());
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=0;i<5005;i++) g[i].clear();
        int cnt=0;
        a.clear();
        cin>>n>>d;
        a.resize(n+1);
        int pp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) pp=a[1];
        }
        // cout<<endl;
        init();
        // cout<<"inited\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int num=bfs(i,j);
                if(num==2) cnt++;
                // cout<<num<<" ";
            }
            // cout<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}