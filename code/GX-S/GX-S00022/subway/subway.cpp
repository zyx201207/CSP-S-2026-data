//I forget Floyd
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
long long ans=LLONG_MAX;
vector<pair<int,int> > e[1005005];
long long dij(int st,int en,int fa,long long cnt){
    if(st==en)return cnt;
    if(cnt>=ans)return ans;
    long long an=LLONG_MAX;
    for(auto j:e[st]){
        int v=j.first;
        int wi=j.second;
        if(v==fa)continue;
        ans=min(ans,dij(v,en,st,cnt+wi));
        an=min(an,dij(v,en,st,cnt+wi));
    }
    return an;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        e[m+i].push_back({i,w[i]});
        e[i].push_back({m+i,w[i]});
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            e[a].push_back({2*m+i,t});
            e[2*m+i].push_back({a,t});
        }
    }
    for(int i=0;i<q;i++){
        int _,_1;
        ans=LLONG_MAX;
        cin>>_>>_1;
        cout<<dij(m+_,m+_1,-1,0)<<'\n';
    }
}
