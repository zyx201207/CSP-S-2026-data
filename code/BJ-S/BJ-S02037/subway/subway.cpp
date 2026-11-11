#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];
int k[500005],a[500005][500005],t[500005][500005];
int x[500005],y[500005];
bool f[500005][500005],book=0;
int ans=0;

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
            f[n][a[i][j]]=1;
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }

    for(int r=1;r<=q;r++){
        book=0;
        for(int i=1;i<=n;i++){
            if(f[i][x[r]]==f[i][y[r]]){
                book=1;
                ans=min(t[i][x[r]]+t[i][y[r]],ans);
            }
        }
        if(book==1){
            continue;
        }
        cout<<ans<<endl;

    }

    return 0;
}
