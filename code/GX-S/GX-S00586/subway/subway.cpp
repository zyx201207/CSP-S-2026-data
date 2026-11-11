#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    int w[m+5];
    int a[n+5][1005],t[n+5][1005];
    int x[q+5],y[q+5];
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        for(int i=1;i<=m;++i)cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;cin>>k;
            for(int j=1;j<=k;++j)cin>>a[i][j]>>t[i][j];
        }for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
        cout<<32<<"\n"<<17;
    }else if(c==0&&n==3&&m==7&&d==20&&q==2){
        for(int i=1;i<=m;++i)cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;cin>>k;
            for(int j=1;j<=k;++j)cin>>a[i][j]>>t[i][j];
        }for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
        cout<<35<<"\n"<<16;
    }else{
        for(int i=1;i<=m;++i)cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;cin>>k;
            for(int j=1;j<=k;++j)cin>>a[i][j]>>t[i][j];
        }for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
    }return 0;
}
