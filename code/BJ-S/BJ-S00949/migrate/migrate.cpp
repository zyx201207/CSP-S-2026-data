#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
long long n,d;
//vector<int> g[2000010];
vector<int> g[2000010];
long long dis[2000010];
unsigned long long cnt[2000010];
int vis[2000010];
void bfs(int s){
//    memset(cnt,0,sizeof(cnt));
//    memset(vis,0,sizeof(vis));
//    memset(dis,0x3f,sizeof(dis));
    fill(cnt,cnt+n+1,0);
    fill(vis,vis+n+1,0);
    fill(dis,dis+n+1,0x3f3f3f3f3f3f3f3fll);
    queue<int> q;
    dis[s]=0;
    cnt[s]=1;
    q.push(s);
    while(!q.empty()){
        int now=q.front();q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int it:g[now]){
            if(dis[it]==dis[now]+1)cnt[it]+=cnt[now];
            if(dis[it]>dis[now]+1){
                dis[it]=dis[now]+1;
                cnt[it]=cnt[now];
                //if(cnt[it]<=2)
                q.push(it);
            }
        }
    }
}
long long Abs(long long p){
    if(p<0)return -p;
    else return p;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(Abs(a[i]-a[j])<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            for(auto it:g[i]){
//                cout<<it<<' ';
//            }
//            cout<<endl;
//        }
        int ans=0;
        for(int s=1;s<=n;s++){
            bfs(s);
//            cout<<"start:"<<s<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<dis[i]<<' ';
//            }
//            cout<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<cnt[i]<<' ';
//            }
//            cout<<endl;
            for(int j=1;j<=n;j++){
                if(cnt[j]==2)ans++;
            }
        }
        for(int i=1;i<=n;i++)g[i].clear();
        cout<<ans/2<<endl;

    }
    return 0;
}
