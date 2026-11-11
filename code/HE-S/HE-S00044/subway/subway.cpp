#include<bits/stdc++.h>
using namespace std;
int an[550];
int c,n,m,d,q,w[500050],k[510],a[510][500010],t[510][500010],x[100050],y[100050];
int main(){
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
        for(int l=1;l<=q;l++){
            int minn=INT_MAX;
            cin>>x[l]>>y[l];
            for(int i=1;i<=n;i++){
                bool g=0,h=0;
                int ans=0;
                for(int j=1;j<=k[i];j++){
                    if(a[i][j]==x[l]){
                        g=true;
                        ans=ans+w[a[i][j]]+t[i][j];
                    }
                    if(a[i][j]==y[l]){
                        h=true;
                        ans=ans+w[a[i][j]]+t[i][j];
                    }
                }
                if(g&&h){
                    if(ans<minn){
                        minn=ans;
                    }
                }
            }
            cout<<minn<<endl;
        }
    return 0;
}
