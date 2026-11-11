#include<bits/stdc++.h>
using namespace std;
namespace Mortis{
using ll=long long;
int L[2000001],R[2000001];
ll x[2000001];
int f[2][2000001],g[2][2000001];
void work(){
    int n;ll d;
    cin>>n>>d;
    for(int i=1;i<=n;++i)cin>>x[i];
    fill(f[0]+1,f[0]+n+1,0),fill(g[0]+1,g[0]+n+1,0);
    for(int i=1,j=1;i<=n;++i){
        for(;x[i]-x[j]>d;++j);
        L[i]=j,++g[0][j];
    }
    for(int i=n,j=n;i>=1;--i){
        for(;x[j]-x[i]>d;--j);
        R[i]=j,++f[0][j];
    }
    copy(f[0]+1,f[0]+n+1,f[1]+1),copy(g[0]+1,g[0]+n+1,g[1]+1);
    for(int i=1;i<=n;++i)
        if(L[i]<i&&R[L[i]]==i)f[1][i]+=f[1][L[i]];
    for(int i=n;i>=1;--i)
        if(R[i]>i&&L[R[i]]==i)g[1][i]+=g[1][R[i]];
    ll res=0;
    for(int i=1;i<n;++i)
        if(L[i]<i&&R[i+1]>i+1)
            res+=(ll)(f[L[i]==L[i+1]][i+1]-(R[i]==i+1))*(g[R[i]==R[i+1]][i]-(L[i+1]==i));
    cout<<res<<'\n';
}
void main(){
    int c,t;
    for(cin>>c>>t;t--;work());
}
}
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    Mortis::main();
    return 0;
}