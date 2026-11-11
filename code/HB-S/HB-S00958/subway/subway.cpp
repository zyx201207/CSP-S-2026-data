#include<bits/stdc++.h>
using namespace std;
int w[500010],k[500010],lu[500][2000],t[500][2000],r[100000][2];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,sum=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i]*2;j++){
            cin>>lu[i][j]>>t[i][j];
            sum+=t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        cin>>r[i][0]>>r[i][1];
    }
    for(int i=1;i<=n;i++){
        cout<<(sum/k[i]*2)<<endl;
    }
    return 0;
}
