#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+2,MAXM=5000+2;
long long ccc,T,n,k,u[MAXN],v[MAXN],ans[MAXN],cnt,allans,t,dis[MAXN];
vector<int>tree[MAXN];
queue<int>q;
bool vis[MAXN];
void dfs2(int now){
    for(auto i:tree[now]){
        if(!vis[i]){
            vis[i]=1;
            dfs2(i);
        }
    }
}
void dfs(int now,int sum){
    if(now>n&&sum!=k){
        return;
    }
    if(now>n){

        memset(vis,0,sizeof(vis));cnt=0;memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=sum;i++){
            if(!vis[ans[i]]){
                vis[ans[i]]=1;
                dfs2(ans[i]);
                cnt++;
            }
        }
        if(cnt>2)
            return;
        //if(ans[1]!=1||ans[2]!=4)
            //return;
        while(!q.empty())
            q.pop();
        for(int i=1;i<=sum;i++){
            dis[ans[i]]=0;
            q.push(ans[i]);

        }
        while(!q.empty()){
            t=q.front();q.pop();
            //cout<<t<<"a"<<endl;
            for(auto i:tree[t]){
                if(dis[i]>dis[t]+1){
                    dis[i]=dis[t]+1;
                    q.push(i);
                }
            }
        }
        long long ttttt=0;
        for(int i=1;i<=n;i++){
            ttttt=max(ttttt,dis[i]);
        }
        allans=min(allans,ttttt);
        return;
    }
    dfs(now+1,sum);
    ans[sum+1]=now;
    dfs(now+1,sum+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>ccc>>T;
    while(T--){
        memset(ans,0,sizeof(ans));allans=1000000000;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
            tree[u[i]].push_back(v[i]);
            tree[v[i]].push_back(u[i]);
        }
        dfs(1,0);
        cout<<allans<<endl;
    }
}
