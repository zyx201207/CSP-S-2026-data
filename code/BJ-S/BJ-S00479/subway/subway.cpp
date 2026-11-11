#include <bits/stdc++.h>
using namespace std;
long long w[10005],ans[10005];
int arr[1000005][1000005][3];
int x[10005],y[10005];

int main(){
freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>arr[i][j][1]>>arr[i][j][2];
    }
    for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++){
        ans[i] += w[x[i]]+w[y[i]];
        for(int i=1;i<=n;i++){
                int jbsaiogdvu=x[q],iuscga=y[q];
            ans=ans+arr[jbsaiogdvu][iuscga]][2];

        }
        cout<<ans<<"\n";
    }

    return 0;
}
