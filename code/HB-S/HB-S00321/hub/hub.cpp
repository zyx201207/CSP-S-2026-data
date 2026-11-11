#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v[15];
int n,k,d[15],fa[15];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int dfs(int now,int fa){
    if(d[now]){
        return 0;
    }
    int mi=INT_MAX;
    for(auto s:v[now]){
        if(s==fa)continue;
        mi=min(mi,dfs(s,now));
    }
    return mi+1;
}
bool check(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int cnt=k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i]&&d[j]&&find(i)!=find(j)){
                for(auto s:v[i]){
                    if(s==j){
                        cnt--;
                        fa[find(i)]=find(j);
                        break;
                    }
                }
            }
        }
    }
    if(cnt<=2){
        return true;
    }return false;
}
int ans=INT_MAX;
void dfs(int now){
    if(now==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(d[i]){
                cnt++;
            }
        }
        if(cnt!=k){
            return;
        }
        int w=0;
        if(!check())return;
        for(int i=1;i<=n;i++){
            w=max(w,dfs(i,0));
        }
        ans=min(ans,w);
        return;
    }
    d[now]=1;
    dfs(now+1);
    d[now]=0;
    dfs(now+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        cout<<ans<<"\n";
        ans=INT_MAX;
    }

    return 0;
}
