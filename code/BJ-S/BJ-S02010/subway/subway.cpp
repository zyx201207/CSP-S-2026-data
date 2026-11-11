#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,m,n,d,q,ans=INT_MAX;
int a[N];
bool v[N];
int k[N];
struct node{
    int id,t;
};
vector<vector<node>>v;
void dfs(int now,int plan,long long sum,bool f,int w){
    if(now==plan){
        sum+=a[plan];
        if(!f)sum+=v[w][plan].t;
        ans=min(ans,sum);
        return;
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(v[i][j].id==now)q.push(i);
        }
    }
    int w1=w;
    while(q.size()){
        int x=q.front();
        q.pop();
        if(w1!=x){
            sum+=vis[x][now]+v[w1][now];
            w1=x;
        }
        for(auto it:v[x]){
            if(!vis[it.id]){
                vis[it.id]=1;
                dfs(it.id,plan,sum,0,w1);
                vis[it.id]=0;
            }
        }
        w1=w;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        vector<node>ve;
        for(int j=1;j<=k[i];j++){
            int id,t;
            cin>>id>>t;
            ve.push_back({id,t});
        }
        v.push_back(ve);
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        ans=INT_MAX;
        int s,t;
        cin>>s>>t;
        queue<int>q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(v[i][j].id==s)q.push(i);
            }
        }
        while(q.size()){
            x=q.front();
            q.pop();
            vis[s]=1
            dfs(s,t,a[s],1,x);
        }
    }
    return 0;
}
