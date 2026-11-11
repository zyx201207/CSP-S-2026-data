/*
CSP-S2 2026
Question.B
Usage Time: 156 min
Expectation Score: 44 points
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN=5e5+10;
int c,n,m,d,q;
vector<pair<int,long long>> line[maxN];
struct node{
    int first,second,id;
    bool operator<(const node x)const{
        return x.first<first;
    }
}query[maxN];
long long dis[maxN],w[maxN],ans[maxN];
void dijkstra(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto it:line[now]){
            if(dis[now]+it.second<dis[it.first]){
                dis[it.first]=dis[now]+it.second;
                q.push(it.first);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        pair<int,int> ln[k];
        for(int j=1;j<=k;j++){
            cin>>ln[j].first>>ln[j].second;
        }
        for(int bg=1;bg<k;bg++){
            for(int ed=bg+1;ed<=k;ed++){
                line[ln[bg].first].push_back({ln[ed].first,ln[ed].second+ln[bg].second});
                line[ln[ed].first].push_back({ln[bg].first,ln[ed].second+ln[bg].second});
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>query[i].first>>query[i].second;
        query[i].id=i;
    }        
    sort(query+1,query+q+1);
    for(int i=1;i<=q;i++){
        int x=query[i].first,y=query[i].second;
        if(x!=query[i-1].first){
            for(int i=1;i<=m;i++){
                dis[i]=LLONG_MAX;
            }
            dis[x]=0;
            dijkstra(x);
        }
        ans[query[i].id]=w[x]+w[y]+dis[y];
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}