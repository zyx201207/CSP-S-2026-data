#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,n,m,d,q,w[555553],k[555],x[155555],y[155555];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];int a,t;
        for(int j=1;j<=k[i];j++)cin>>a>>t;
    }for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=q;i++)cout<<w[x[i]]+w[y[i]]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
