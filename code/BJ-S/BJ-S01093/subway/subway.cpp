#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N=505,M=5e5+505;
int c,n,m,d,q,cnt;
int w[N];
vector<pii> e[M];
int dis[M];
void dijk(int x){
    for(int i=1;i<=n+m;i++)
        dis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,x});
    dis[x]=0;
    while(!q.empty()){
        pii u=q.top();
        q.pop();
        if(u.first>dis[u.second]) continue;
        for(pii v:e[u.second])
            if(dis[v.second]>dis[u.second]+v.first){
                dis[v.second]=dis[u.second]+v.first;
                q.push({dis[v.second],v.second});
            }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            e[a].push_back({t,m+i});
            e[m+i].push_back({t,a});
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        dijk(l);
        cout<<w[l]+w[r]+dis[r]<<endl;
    }
    return 0;
}
