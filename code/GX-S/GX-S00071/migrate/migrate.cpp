#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long x[maxn];
vector<long long>g[maxn];
long long d[maxn];
long long ans;
priority_queue<long long,vector<long long>,greater<long long > >q;
int dijkstra(int s){
    q.push(s);
    d[s]=0;
    long long cnt=0;
    while(!q.empty()){
        auto u=q.top();q.pop();
        if(d[u]<u)continue;
        for(auto v:g[u]){
            if(d[u]+1<d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }else if(d[u]+1==d[v])cnt++;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&abs(x[i]-x[j])<=d){
                    g[x[i]].push_back(x[j]);
                    g[x[j]].push_back(x[i]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dijkstra(x[i])>0)ans+=dijkstra(x[i]);
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
