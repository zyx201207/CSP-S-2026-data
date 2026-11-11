#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int w[5*N],k[5*N],a[5][5*N],t[5][5*N],x[N],y[N];
void solve1(){
    for(int i=1;i<=q;i++)
        cout<<w[x[i]]+w[y[i]]<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    solve1();
    return 0;
}
