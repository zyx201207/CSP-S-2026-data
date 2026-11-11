#include<bits/stdc++.h>
using namespace std;
pair<int,long long> z[500005][25];
int cnt[510000];
#define int long long
int mp[505][505],W[510000];
vector<int> to[510000],wi[510000];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>W[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
            z[a][++cnt[a]].first=i;
            z[a][cnt[a]].second=t;
            to[a].push_back(i+m);
            to[i+m].push_back(a);
            wi[a].push_back(t);
            wi[i+m].push_back(t);
        }
    }
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=n;i++){
        for(int j=0;j<to[i+m].size();j++){
            int mid=to[i+m][j];
            for(int k=0;k<to[mid].size();k++){
                int v=to[mid][k]-m;
                mp[i][v]=min(mp[i][v],wi[i+m][j]+wi[mid][k]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mp[j][k]=min(mp[j][k],mp[j][i]+mp[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)mp[i][i]=0;
    while(q--){
        int s,t;cin>>s>>t;
        int ans=LONG_LONG_MAX;
        for(int i=1;i<=cnt[s];i++){
            for(int j=1;j<=cnt[t];j++){
                ans=min(ans,mp[z[s][i].first][z[t][j].first]+z[s][i].second+z[t][j].second);
            }
        }
        cout<<ans+W[s]+W[t]<<'\n';
    }
    return 0;
}