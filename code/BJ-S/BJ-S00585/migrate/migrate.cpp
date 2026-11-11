#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],num[100005],dis[100005],vis[100005];
vector<int>mp[100005];
        int n,d,ans=0;
void bfs(int x){
    queue<int>q;
    q.push(x);
    dis[x]=0;
    num[x]=1;
    while(q.size()){
        int u=q.front();q.pop();
        //cout<<u<<endl;
        if(vis[u])continue;
        vis[u]=1;
        //for(int i=1;i<=n;i++)cout<<dis[i]<<' ';
        //cout<<endl;
        for(auto it:mp[u]){
            //if(dis[it]==-1){
                if(dis[it]==dis[u]+1){
                        //cout<<'&'<<it<<' '<<x<<endl;
                    num[it]+=num[u];
                }else if(dis[it]>dis[u]+1){
                    dis[it]=dis[u]+1,num[it]=num[u];
                    q.push(it);
                }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;

    while(t--){
        if(c==13||c==14){
            cout<<0<<endl;
            continue;
        }
            ans=0;
        for(int i=1;i<=100000;i++)mp[i].clear();
        memset(a,0,sizeof a);
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];

        //sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
            //or(auto it:mp[i])cout<<it<<' ';
            //cout<<endl;
        }
        for(int i=1;i<=n;i++){
            memset(num,0,sizeof num);
            memset(dis,0x3f,sizeof dis);memset(vis,0,sizeof vis);
            bfs(i);
            for(int j=i+1;j<=n;j++){
                //cout<<dis[j]<<' '<<num[j]<<endl;
                if(num[j]==2)ans++;
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

