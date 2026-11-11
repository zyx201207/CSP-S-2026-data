#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=5005;
int w[N],k[N],a[N][N],t[N][N];
struct node{
    int l,id;
};
vector<node>v[N];
int ans=0;
void dfs(int y,int line,int i,int sum){
    if(a[line][i]==y){
        ans+=sum;
        return;
    }
    else if(i==k[line]) return;
    else{
        dfs(y,line,i+1,sum);
        for(int k=0;k<v[a[line][i]].size();k++){
            node tem=v[a[line][i]][k];
            dfs(y,tem.l,tem.id,sum+t[tem.l][tem.id]+t[line][k]);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            v[a[i][j]].push_back({i,j});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int Ans=1e18;
        for(int i=0;i<v[x].size();i++){
            dfs(y,v[x][i].l,v[x][i].id,0);
            Ans=min(Ans,ans);
            ans=0;
        }
        cout<<Ans+w[x]+w[y]<<endl;
    }
    return 0;
}
