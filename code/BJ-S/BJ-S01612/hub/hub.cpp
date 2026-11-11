#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,d[1000010];
vector<int>e[1000010];
int find(int x,int fa){
    d[x]=0;
    int now=x;
    for(int to:e[x]){
        if(to==fa)continue;
        int p=find(to,x);
        if(d[x]<d[to]+1){
            d[x]=d[to]+1;
            now=p;
        }
    }
    return now;
}
void solve(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++)e[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(c==0||c==7||c==11||c==12){
        int p=find(1,0);
        int pp=find(p,0);
        d[p]--;
        if(d[p]%4==0)cout<<d[p]/4<<'\n';
        else cout<<d[p]/4+1<<'\n';
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
