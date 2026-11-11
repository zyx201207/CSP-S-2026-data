#include <bits/stdc++.h>
#define ll long long
using namespace std;
// int d[1000005],f[1000005][21];
// vector<int> v1[1000005],tr[1000005];
// bool fixed[1000005];
// void dfs(int id,int fath){
//     d[id]=d[fath]+1;
//     f[i][0]=fath;
//     for(auto i:v1[id]){
//         if(i!=fath){
//             dfs(i,id);
//         }
//     }
// }
// int jp(int id,int nj){
//     if(nj==0){
//         return id;
//     }
//     int cnt=1<<20;
//     for(int i=20;i>=0;i--){
//         if(cnt<=nj){
//             return jp(f[id][i],nj);
//         }
//         cnt>>=1;
//     }
// }
// int aj(int xx,int yy){
//     if(xx==yy){
//         return xx;
//     }
//     if(f[xx][0]==f[yy][0]){
//         return f[xx][0];
//     }
//     for(int i=20;i>=0;i--){
//         if(f[xx][i]!=f[yy][i]){
//             return aj(f[xx][i],f[yy][i]);
//         }
//     }
// }
// int lca(int xx,int yy){
//     if(d[xx]<d[yy]){
//         swap(xx,yy);
//     }
//     if(d[xx]!=d[yy]){
//         xx=jp(xx,d[xx]-d[yy]);
//     }
//     return aj(xx,yy);
// }
// void warn(int st,int id,int lst,int dis){
//     if(dis==0){
//         return;
//     }
//     for(auto i:v1[id]){
//         if(i!=lst){
//             tr[i].push_back(st);
//             warn(st,i,id,dis-1);
//         }
//     }
// }
// bool check(int x){
//     memset(tr,0,sizeof(tr));
//     for(int i=1;i<=n;i++){
//         warn(i,i,0,x);
//     }
//     bool flag=1;
//     while(1){
//         flag=1;
//         int mx=0,mxid;
//         for(int i=1;i<=n;i++){
//             for(auto j:tr[i]){
                
//             }
//         }
//     }
    
// }
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cout<<1;
        // int n,k;
        // cin>>n>>k;
        // int u,v;
        // for(int i=1;i<n;i++){
        //     cin>>u>>v;
        //     v1[u].push_back(v);
        //     v1[v].push_back(u);
        // }
        // dfs(1,0);
        // for(int j=20;j>=1;j--){
        //     for(int i=1;i<=n;i++){
        //         f[i][j]=f[i[j-1]][j-1];
        //     }
        // }
        // int l=1,r=n,mid;
        // while(l<r){
        //     mid=l+r-1>>1;
        //     if(check(mid)){
        //         r=mid;
        //     }
        //     else{
        //         l=mid+1;
        //     }
        // }
    }
}