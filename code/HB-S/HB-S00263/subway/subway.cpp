#include<bits/stdc++.h>
using namespace std;
struct node{
    long long id,time;
};
long long w[500005];
long long a[505][100005],t[505][100005];
vector<node> g[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
        for(int j=2;j<=k;j++){
            g[a[i][j]].push_back({a[i][j-1],t[i][j]});
            g[a[i][j]].push_back({a[i][j-1],t[i][j]});
        }
    }
    long long ans=0;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans+=w[x]+w[y];
        queue<int> qu;
        qu.push(x);
        int q=qu.front();
        for(auto j:g[q]){
            qu.push(j.id);
            qu.pop();
            q=qu.front();

        }
        cout<<ans<<endl;
    }
    return 0;
}
