#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>v[N];
bool a[N];
int cnt=0;
int ans=1000000;
    int n,k;
int dfs2(int now,int fa){
    if(a[now])return 0;
    int len=1e9;
    for(auto it:v[now]){
        if(it==fa)continue;
        len=min(len,dfs2(it,now)+1);
    }
    return len;
}
void check(){
    int cur=0;
    for(int i=1;i<=n;i++){
        cur=max(cur,dfs2(i,0));
    }
    ans=min(ans,cur);
}
void dfs(int now,int fa){
    if(cnt<=k&&cnt){
        check();
    }
    for(auto it:v[now]){
        if(it==fa)continue;
        cnt++;
        a[now]=1;
        dfs(it,now);
        cnt--;
        a[now]=0;
        dfs(it,now);
    }
}
void solve(){
    ans=1e9;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        v[i].clear();
    }
    cout<<ans<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}