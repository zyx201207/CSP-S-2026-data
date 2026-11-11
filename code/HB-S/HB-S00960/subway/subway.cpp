#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int m,n,c,d,q;
int w[N];
struct node{
    int a,t;
}p[501][21];
int dp[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>p[i][j].a>>p[i][j].t;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(y>x) swap(x,y);
        cout<<dp[x][y]+w[x]+w[y];
    }
    return 0;
}
