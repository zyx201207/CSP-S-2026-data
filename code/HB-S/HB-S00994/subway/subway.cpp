#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[501][500001],w[500001],t[501][500001],b[100001],e[100001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)
        cin>>b[i]>>e[i];
    for(int i=1;i<=q;i++){
        long long ans=w[b[i]]+w[e[i]]+2*t[1][b[i]];
        cout<<ans<<'\n';
    }
    return 0;
}
