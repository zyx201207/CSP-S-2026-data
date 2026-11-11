#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000005];
vector<int> g[5005];
// int dis[5005][5005];
// int f[5005][5005];
// bool vis[5005][5005];
int dis[2000005];
int f[2000005];
bool vis[2000005];
// int work1(){
//     cin>>n>>d;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         g[i].clear();
//         for(int j=1;j<=n;j++){
//             f[i][j]=0;
//             dis[i][j]=1e18;
//             vis[i][j]=0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             if(i==j){
//                 continue;
//             }
//             if(abs(a[i]-a[j])<=d){
//                 g[i].push_back(j);
//             }
//             vis[i][j]=0;
//         }
//         f[i][i]=1;
//     }
//     for(int i=1;i<=n;i++){
//         priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//         q.push({0,i});
//         dis[i][i]=0;
//         // cout<<i<<":\n";
//         while(!q.empty()){
//             int u=q.top().second;
//             // cout<<u<<endl;
//             q.pop();
//             if(vis[i][u]){
//                 continue;
//             }
//             vis[i][u]=1;
//             for(auto v : g[u]){
//                 if(dis[i][v]>dis[i][u]+1){
//                     dis[i][v]=dis[i][u]+1;
//                     q.push({dis[i][v],v});
//                     f[i][v]=f[i][u];
//                     // cout<<"update 1 f"<<v<<" to "<<f[i][v]<<endl;
//                 }else if(dis[i][v]==dis[i][u]+1){
//                     f[i][v]+=f[i][u];
//                     // cout<<"update 2 f"<<v<<" to "<<f[i][v]<<endl;
//                 }
//             }
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             ans+=(f[i][j]==2);
//             // if(f[i][j]==2){
//             //     cout<<i<<" "<<j<<endl;
//             // }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
int work2(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[2]-a[1]>d){
        cout<<0<<endl;
        return 0;
    }
    int x=d/(a[2]-a[1]);
    //0 7 14 21 28 35 42 49 56 63 70 77 d=606662
    if(x==1){
        cout<<0<<endl;
        return 0;
    }
    cout<<max(0ll,n-2*x+1)<<endl;
    return 0;
}
int work3(){

    return 0;
}
int p[2000005];
int work4(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        p[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
        for(int j=1;j<=n;j++){
            f[j]=0;
            dis[j]=1e18;
            vis[j]=0;
        }
        q.push({0,i});
        f[i]=1;
        dis[i]=0;
        // cout<<i<<":\n";
        while(!q.empty()){
            int u=q.top().second;
            // cout<<u<<endl;
            q.pop();
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            for(int v=u;v<=p[u];v++){
                if(dis[v]>dis[u]+1){
                    dis[v]=dis[u]+1;
                    q.push({dis[v],v});
                    f[v]=f[u];
                    // cout<<"update 1 f"<<v<<" to "<<f[i][v]<<endl;
                }else if(dis[v]==dis[u]+1){
                    f[v]+=f[u];
                    // cout<<"update 2 f"<<v<<" to "<<f[i][v]<<endl;
                }
            }
        }
        for(int j=i+1;j<=n;j++){
            ans+=f[j]==2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=10){
        while(t--){
            work4();
        }
    }else if(c<=12){
        while(t--){
            work2();
        }
    }else if(c<=14){
        while(t--){
            work4();
        }
    }else if(c<=18){
        while(t--){
            work4();
        }
    }else{
        while(t--){
            work4();
        }
    }
    return 0;
}
//48 (No special B and C)