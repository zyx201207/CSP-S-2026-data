#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long w[N],dis[1000][1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=0;i<1000;i++)for(int j=0;j<1000;j++)dis[i][j]=1e18;
    for(int i=0;i<1000;i++)dis[i][i]=0;
    int t,n,m,d,q;
    scanf("%d%d%d%d%d",&t,&n,&m,&d,&q);
    for(int i=0;i<m;i++)cin>>w[i];
    vector<pair<int,int>> a[N];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,w;
            cin>>x>>w,x--;
            a[x].push_back({i,w});
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<a[i].size();j++)
            for(int k=0;k<j;k++)
                dis[a[i][j].first][a[i][k].first]=dis[a[i][k].first][a[i][j].first]=min(dis[a[i][j].first][a[i][k].first],0ll+a[i][j].second+a[i][k].second);
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v),u--,v--;
        long long ans=1e18;
        for(auto i:a[u])
            for(auto j:a[v])
                ans=min(ans,i.second+dis[i.first][j.first]+j.second);
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}

