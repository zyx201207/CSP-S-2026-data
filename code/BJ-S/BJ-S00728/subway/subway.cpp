#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
int n,m,c,d,q,a[20005],w[20005];
vector<pii>vec[20005];
int dis[20005],x,y,k,t[20005];
priority_queue<pii,vector<pii>,greater<pii> >pq;
void dj(int x,int y){
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        for(auto i:vec[p.se]){
            if(dis[i.se]>i.fi+dis[p.se]){
                dis[i.se]=dis[p.se]+i.fi;
                pq.push({dis[i.se],i.se});
            }
        }
    }
}
map<pii,int>mp;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
        }
        for(int l=1;l<=k;l++){
            for(int j=l+1;j<=k;j++){
                vec[a[l]].push_back({t[l]+t[j],a[j]});
                vec[a[j]].push_back({t[l]+t[j],a[l]});
            }
        }
    }
    if(m<=1000){
        while(q--){
            cin>>x>>y;
            if(mp[{x,y}]>0){
                cout<<mp[{x,y}]+w[x]+w[y]<<'\n';
                continue;
            }
            dj(x,y);
            for(int i=1;i<=m;i++){
                mp[{x,i}]=mp[{i,x}]=dis[i];
            }
            cout<<dis[y]+w[x]+w[y]<<'\n';
        }
        return 0;
    }
    while(q--){
        cin>>x>>y;
        dj(x,y);
        cout<<dis[y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
