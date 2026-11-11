#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll x,y,prv;
}frt;
ll a[1000010],dis[1000010],f[1000010],n,d,ans;
queue<node>q;vector<int>v[100010];
void BFS(ll s){
    for(int i=1;i<=n;i++)dis[i]=-1;
    for(int i=1;i<=n;i++)f[i]=0;
    while(q.size())q.pop();
    q.push({s,0,-1});dis[s]=0;
    while(q.size()){
        frt=q.front();q.pop();
        if(dis[frt.x]==-1)dis[frt.x]=frt.y,f[frt.x]=1;
        else if(frt.y>dis[frt.x])continue;
        else if(frt.y<dis[frt.x])dis[frt.x]=frt.y,f[frt.x]=1;
        else f[frt.x]++;
        for(auto i:v[frt.x]){
            if(dis[i]>=0&&dis[i]<frt.y+1)continue;
            if(i==frt.prv)continue;
            q.push({i,frt.y+1,frt.x});
        }
    }
    for(int i=1;i<=n;i++){ if(f[i]==2){ ans++; } }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,T;
    cin>>c>>T;
    if(c<=10){
        while(T--){
            cin>>n>>d;ans=0;
            for(int i=1;i<=n;i++)v[i].clear();
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(abs(a[i]-a[j])<=d&&j!=i)v[i].push_back(j);
            for(int i=1;i<=n;i++)BFS(i);
            cout<<ans/2<<"\n";
        }
    }
    return 0;
}