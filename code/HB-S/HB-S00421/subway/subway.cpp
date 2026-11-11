#include<bits/stdc++.h>
#define it long long
using namespace std;
it c,n,m,d,q,w[500005],a[505][505],dis[500005][25],cnt[500005];
unordered_map<it,it> mp[505];
vector<it> st[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(it i=1;i<=m;i++) cin>>w[i],dis[i][0]=0x3f3f3f3f3f3f3f3f;
    for(it i=1;i<=n;i++){
        it k,x,y;
        cin>>k;
        for(it j=1;j<=k;j++){
            cin>>x>>y;
            dis[x][++cnt[x]]=y;
            mp[i][x]=cnt[x];
            st[x].push_back(i);
        }
    }
    memset(a,0x3f,sizeof(a));
    for(it i=1;i<=n;i++) a[i][i]=0;
    for(it i=1;i<=m;i++){
        for(it x:st[i]){
            for(it y:st[i]){
                if(x>=y) continue;
                a[x][y]=min(a[x][y],dis[i][mp[x][i]]+dis[i][mp[y][i]]);
                a[y][x]=a[x][y];
            }
        }
    }
    for(it k=1;k<=n;k++){
        for(it i=1;i<=n;i++){
            for(it j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--){
        it s,t,ans=LLONG_MAX;
        cin>>s>>t;
        for(it i:st[s]){
            for(it j:st[t]){
                ans=min(ans,w[s]+dis[s][mp[i][s]]+a[i][j]+dis[t][mp[j][t]]+w[t]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
