#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,qu;
int w[500010];
struct station{
    int line[30],t[30],x=0;
};
station s[500010];
vector<pair<int,int>> v[510];
bool vis[500010];
long long dis[500010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void dijsktra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    q.push({0,s});
    dis[s]=0;
    while (q.size()){
        int k=q.top().second;
        q.pop();
        if (vis[k]) continue;
        vis[k]=true;
        for (auto x:v[k]){
            int w2=x.first;
            if (dis[x.second]>dis[k]+w2){
                dis[x.second]=dis[k]+w2;
                q.push({dis[x.second],x.second});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qu;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int st,time;
            cin>>st>>time;
            s[st].line[++s[i].x]=i;
            s[st].t[s[i].x]=time;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=s[i].x;i++){
            for (int k=j+1;k<=s[i].x;k++){
                int w1=s[i].t[j]+s[i].t[k];
                v[s[i].line[j]].push_back({s[i].line[k],w1});
                v[s[i].line[k]].push_back({s[i].line[j],w1});
            }
        }
    }
    while (qu--){
        int r1,r2;
        long long ans=0x3f3f3f3f3f3f3f3f;
        cin>>r1>>r2;
        for (int i=1;i<=s[r1].x;i++){
            dijsktra(s[r1].line[i]);
            for (int j=1;j<=s[r2].x;j++){
                ans=min(ans,dis[s[r2].line[j]]+s[r1].t[i]+w[r1]+s[r2].t[i]+w[r2]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
