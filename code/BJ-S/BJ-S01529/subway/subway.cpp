#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int c,n,m,d,q1,l,r;
long long w[N],k,a[510][N],t[510][N];
long long ans=1e18;
struct node{
    int uc,v,vc;
};
struct node1{
    long long cost,u;
};
vector<node>g[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q1;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            for(int l=1;l<j;l++){
                node d1={t[i][j],a[i][l],t[i][l]};
                node d2={t[i][l],a[i][j],t[i][j]};
                g[a[i][j]].push_back(d1);
                g[a[i][l]].push_back(d2);
            }
        }
    }
    while(q1--){
        ans=1e18;
        cin>>l>>r;
        queue<node1>q;
        node1 d1={w[l],l};
        q.push(d1);
        while(!q.empty()){
            int u1=q.front().u;
            if(u1==r){
                ans=min(ans,q.front().cost+w[q.front().u]);
                break;
            }else{
                int l=g[u1].size();
                for(int i=0;i<l;i++){
                    node1 d1={q.front().cost+g[u1][i].uc+g[u1][i].vc,g[u1][i].v};
                    q.push(d1);
                }
            }
            q.pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}