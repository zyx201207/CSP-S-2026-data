#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#define endl '\n'
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,ll>;
int c,n,m,d,q;
ll w[500005],f[505][505];
vector<pii> v[500005];
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        for(int j=1;j<=k;j++){
            int a,t; cin>>a>>t;
            v[a].push_back({i,t});
        }
        f[i][i]=0;
    }
    for(int i=1;i<=m;i++) for(pii a:v[i]) for(pii b:v[i]) f[a.fi][b.fi]=min(f[a.fi][b.fi],a.se+b.se);
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y; ll mn=0x3f3f3f3f3f3f3f3f; cin>>x>>y;
        for(pii a:v[x]) for(pii b:v[y]) mn=min(mn,f[a.fi][b.fi]+a.se+b.se);
        cout<<mn+w[x]+w[y]<<endl;
    }
    return 0;
}