#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
unordered_map<long long,int>mp;
long long mix(int i,int j){return i*1000000+j;}
vector<int>e[500005];
bool vis[500005];
int mis[500005];
int dis(int x,int y){
    memset(vis,0,sizeof(vis));
    memset(mis,0x3f,sizeof(mis));
    queue<int>q;
    q.push(x);
    mis[x]=0;
    while(!q.empty()){
        int u=q.front();
        vis[u]=1;
        q.pop();
        for(auto it:e[u]){
            if(!vis[it]){
                q.push(it);
                mis[it]=min(mis[it],mis[u]+mp[mix(u,it)]);
            }
        }
    }
    return mis[y];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        queue<int>qa;
        queue<int>qt;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            for(int p=1;p<j;p++){
                int b=qa.front(),c=qt.front();
                qa.push(qa.front());qa.pop();
                qt.push(qt.front());qt.pop();
                long long m1=mix(a,b),m2=mix(b,a);
                if(mp[m1]!=0){
                    mp[m1]=min(mp[m1],t+c);
                    mp[m2]=mp[m1];
                }
                else{
                    mp[m1]=t+c;
                    mp[m2]=t+c;
                    e[a].push_back(b);
                    e[b].push_back(a);
                }
            }
            qa.push(a);
            qt.push(t);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+dis(x,y)<<endl;
    }
    return 0;
}
