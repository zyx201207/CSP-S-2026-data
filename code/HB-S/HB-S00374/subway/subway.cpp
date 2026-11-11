#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{ll len,from,to,value;};
ll c,n,m,d,q,x,y,ans=0,w[550];
vector<node>v;
void pp()for(ll i=0;i<v.size();i++,cout<<i<<endl)cout<<v[i].from<<" "<<v[i].to<<" "<<v[i].value<<" "<<v[i].len<<endl;
ll bfs(ll s,ll e){
    queue<node>q;
    node tmp;
    ll len=v.size();
    bool visited[m+20][m+20]={{0},{0}};
    tmp.from=0;
    tmp.len=0;
    tmp.value=0;
    tmp.to=s;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.front();
        if(tmp.to==e)return tmp.len;
        q.pop();
        for(ll i=0;i<len;i++){
            if(v[i].from==tmp.to&&(visited[v[i].from][v[i].to]==0||visited[v[i].to][v[i].from]==0)){
                //cout<<endl<<endl;
                visited[v[i].from][v[i].to]=1;
                visited[v[i].to][v[i].from]=1;
                node tmpp=v[i];
                tmpp.len=tmp.len+tmpp.value;
                //cout<<tmpp.from<<" "<<tmpp.to<<" "<<tmpp.value<<" "<<tmpp.len<<endl;
                q.push(tmpp);
            }
        }
    }
    return 0;
}
bool cmp(node x,node y){
    if(x.from!=y.from)return x.from<y.from;
    else return x.value<y.value;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    ll pos=1;
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++){
            ll a,t;
            node tmp;
            cin>>a>>t;
            tmp.from=m+i;
            tmp.len=0;
            tmp.to=a;
            tmp.value=t;
            v.push_back(tmp);
            tmp.from=a;
            tmp.len=0;
            tmp.to=m+i;
            tmp.value=t;
            v.push_back(tmp);
        }
    }
    sort(v.begin(),v.end(),cmp);
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+bfs(x,y)<<endl;
    }
    return 0;
}
