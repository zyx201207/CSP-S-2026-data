#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
struct node{
    int p,s;
};
bool f[2000010];
int r(int s1,int s2,vector<int> g[]){
    memset(f,0,sizeof f);
    queue<node> q;
    q.push({s1,0});
    q.push({s2,0});
    int rm=0;
    f[s1]=f[s2]=1;
    while(q.size()<k){
        queue<node> qt;
        int pos,mn=0x3f3f3f3f;
        while(q.size()){
            node t=q.front();q.pop();
            for(int i=0;i<g[t.p].size();i++){
                int len=t.s+1;
                if(len<mn&&f[g[t.p][i]]==0){
                    mn=len,pos=g[t.p][i];
                }
            }
            q.push(t);
        }
        q.push({pos,mn});
    }
    while(q.size()){
        rm=max(rm,q.front().s);
        q.pop();
    }
    return rm;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        vector<int> g[2000010];
        int u,v;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int mn=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mn=min(mn,r(i,j,g));
            }
        }
        cout<<mn<<"\n";
    }
    return 0;
}
