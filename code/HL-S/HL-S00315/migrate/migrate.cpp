#include <bits/stdc++.h>
using namespace std;
using ll=long long;
// ll a[2200000];
// void solve(){
//     int n;
//     ll d;
//     cin>>n>>d;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     // for(int i=2;i<=n;i++){
//     //     // cerr<<a[i]-a[i-1]<<"\n";

//     // }
//     a[0]=1000000000000000000ll*5-10;
//     a[n+1]=-1000000000000000000ll*5+10;
//     int front=0;
//     ll ans=0,res=1;
//     bool hasans=0;
//     for(int i=4;i<=n;i++){
//         cerr<<i<<":\n";
//         int i1=i-3,i2=i-2,i3=i-1,i4=i;
//         if(a[i]-a[i-1]>d){
//             cerr<<ans<<" "<<res<<" "<<front<<" "<<hasans<<"\n";
//             if(hasans)ans+=res*(front+1);
//             res=1;
//             hasans=0;
//             continue;
//         }
//         if(a[i2]-a[i1]<=d&&a[i3]-a[i2]<=d&&a[i4]-a[i3]<=d){
//             if(a[i3]-a[i1]<=d&&a[i4]-a[i2]<=d){
//                 if(a[i4]-a[i1]>d){
//                     // if(a[i1]-a[i-4]<=d){
//                     //     ans+=res;
//                     //     res=1;
//                     //     hasans=0;
//                     //     front=0;
//                     // }
//                     cerr<<ans<<" "<<res<<" "<<front<<" "<<hasans<<"\n";
//                     res*=front+1;
//                     hasans=1;
//                     front=0;
//                     if(a[i+1]-a[i3]<=d){
//                         cerr<<ans<<" "<<res<<" "<<front<<" "<<hasans<<"\n";
//                         if(hasans)ans+=res;
//                         res=1;
//                         hasans=0;
//                     }
//                     continue;
//                 }
//             }
//         }
//         front++;
//     }
//     // cerr<<ans<<" "<<res<<" "<<hasans<<"\n";
//     if(hasans)ans+=res*(front+1);
//     cout<<ans<<"\n";
// }
ll a[2200000];
vector<int> g[2200000];
queue<int> q;
int dis[2200000],cnt[2200000];
void bfs(int x){
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    dis[x]=0;
    q.push(x);
    while(!q.empty()){
        int t=q.front();q.pop();
        // cerr<<t<<" ";
        for(int i=0;i<g[t].size();i++){
            int y=g[t][i];
            if(dis[t]+1==dis[y]){
                cnt[y]++;
                // q.push(y);
            }else if(dis[t]+1<dis[y]){
                dis[y]=dis[t]+1;
                cnt[y]=1;
                q.push(y);
            }
        }
    }
    // cerr<<"\n";
}
void solve(){
    int n;
    cin>>n;
    ll d;
    cin>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[i].clear(); // duo ce bu qing kong, gua ling liang hang lei.
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(a[j]-a[i])<=d&&i!=j){
                g[i].push_back(j);
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        bfs(i);
        for(int j=i+1;j<=n;j++){
            if(cnt[j]==2){ans++;cerr<<i<<" "<<j<<" "<<cnt[j]<<" "<<dis[j]<<"\n";}
            // if(cnt[j]==2&&dis[j]<2)
            // cerr<<i<<" "<<j<<" "<<cnt[j]<<" "<<dis[j]<<"\n";
        }
    }
    cout<<ans<<"\n";
}
int main(){
#ifndef HCX
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
// build:
// g++ migrate.cpp -o migrate -O2 -Wall -Wextra -Wconversion -Wshadow
// debug:
// g++ migrate.cpp -o migrate -DHCX -g -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wshadow