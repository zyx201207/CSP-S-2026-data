#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],a[505][500005],t[505][500005],x[500005],y[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }if(n==2){
        // vector<pair<int,int>>chond;
        int ans=0,mint=1;
        for(int i=1;i<=k[1];i++){
            for(int j=1;j<=k[2];j++){
                if(a[1][i]==a[2][j]){
                    //chond.push_back({i,j});
                    mint=(a[1][i]<a[1][mint])?i:mint;
                }
            }
        }for(int i=1;i<=q;i++){
            ans=0;
            ans+=w[x[i]]+w[y[i]];
            ans+=t[1][x[i]]+t[2][y[i]];
            ans+=t[1][mint]+t[2][mint];
            cout<<ans<<endl;
        }
    }
}
