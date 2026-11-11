#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1000];
int a[1000][1000],t[1000][1000];
int x[1000],y[1000],k[1000];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
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
        cin>>x[i]>>y[i];
    }
    //bububu,wo wu yi shi feng nu de.Linux wo ai ni.
    //wo yao shang mi huo xing wei da shang,diao yu qu TvT.
    //feropen("crystal.in","r",stdin);
    return 0;
}

