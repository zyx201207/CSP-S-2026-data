#include<bits/stdc++.h>
using namespace std;
int w[10005];
int a[10005][10005],t[10005][10005],ds[1005][5];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>ds[i][1]>>ds[i][2];
    }
    int ans=0,a1,a2;
    for(int i=1;i<=q;i++){
        ans=0;
        a1=ds[i][1];
        a2=ds[i][2];
        ans+=w[a1];
        ans+=t[i][a1];
        ans+=t[i][a2];
        ans+=w[a2];
        cout<<ans<<'\n';
    }
    return 0;
}
