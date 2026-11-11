#include<bits/stdc++.h>
#define N 102
using namespace std;
int c,t;
int n,k;
int dis[N][N];
void work(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        dis[u][v]=dis[v][u]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int res=n+1;
    for(int s=0;s<(1<<n);s++){
        if(__builtin_popcount(s)!=k)continue;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!((s>>(i-1))&1))continue;
            for(int j=1;j<=n;j++){
                if(!((s>>(j-1))&1))continue;
                if(dis[i][j]==1)cnt++;
            }
        }
        if(cnt<k-2)continue;
        int tmp=0;
        for(int i=1;i<=n;i++){
            int mnn=n+1;
            for(int j=1;j<=n;j++){
                if(!((s>>(j-1))&1))continue;
                mnn=min(mnn,dis[i][j]);
            }
            tmp=max(tmp,mnn);
        }
        res=min(res,tmp);
    }
    cout<<res<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)work();
}