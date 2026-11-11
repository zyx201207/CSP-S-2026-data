#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,x[500][500],y[500][500],a1,a2,sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x[i][j]>>y[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>a1>>a2;

        for(int j=a1;j<=a2;j++){
            sum+=min(y[j],y[j+1]);
            sum+=w[j];
        }
        cout<<sun<<endl;;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
