#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[5005][5005],ans,w[500005],x,t[500005],z[500005],v[5005][5005],l,r,b;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        a[m][m]=1e9;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=x;j++){
            cin>>z[j]>>t[j];
        }
        for(int j=1;j<x;j++){
            a[z[j]][z[j+1]]+=t[j];
            a[z[j+1]][z[j]]+=t[j];
        }
    }
    while(q--){
        cin>>l>>r;
        ans=w[l]+w[r];
        for(int k=1;k<=m;k++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<i;j++){
                    if(j==k) continue;
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                }
            }
        }
        cout<<ans+a[l][r];
    }
    return 0;
}
