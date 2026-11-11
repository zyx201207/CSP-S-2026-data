#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXM=500005,MAXN=505;
int c,n,m,d,q;
int w[MAXM];
int k[MAXN];
int a[MAXN][MAXM],t[MAXN][MAXM];
int x[100005],y[100005];
// ll dfs(int a,int b,ll sum){
//     if(a==b) return sum;
    
// }
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        ll ans;
        cin>>x[i]>>y[i];
        ans+=w[x[i]]+w[y[i]];
        
        // ans+=dfs(x[i],y[i],0);
        cout<<ans;
    }
    return 0;
}