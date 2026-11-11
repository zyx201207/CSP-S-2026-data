#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long mp[510][510];
int cnt[500100];
struct node{
    int to;
    long long t;
}a[500100][30];
long long w[500100];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int ai,ti;
            cin>>ai>>ti;
            cnt[ai]++;
            a[ai][cnt[ai]].to=i;
            a[ai][cnt[ai]].t=ti;
        }
    }
    //build map
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=n;i++){
        mp[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=cnt[i];++j){
            int u=a[i][j].to;
            long long u_w=a[i][j].t;
            for(int k=j+1;k<=cnt[i];++k){
                int v=a[i][k].to;
                long long v_w=a[i][k].t;
                mp[v][u]=mp[u][v]=min(mp[u][v],u_w+v_w);
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            for(int k=1;k<=n;++k){
            mp[i][j]=mp[j][i]=min(mp[j][i],mp[j][k]+mp[k][i]);
            }
        }
    }
    //ans
    while(q--){
        int x,y;
        long long minn=1e18;
        long long ans=0;
        cin>>x>>y;
        for(int i=1;i<=cnt[x];i++){
            int u=a[x][i].to;
            for(int j=1;j<=cnt[y];j++){
                int v=a[y][j].to;
                minn=min(minn,mp[u][v]+a[x][i].t+a[y][j].t);
            }
        }
        ans=w[x]+w[y]+minn;
        cout<<ans<<endl;
    }
    return 0;
}
