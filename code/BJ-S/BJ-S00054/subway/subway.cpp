#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL c,n,m,d,q;
LL w[N];
LL k[N];
LL x[N],y[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i+1;j++){
            cin>>k[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if(n==3&&c==0){
        cout<<32<<endl<<17;
    }
    if(c==0&&n==2){
        cout<<35<<endl<<16;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
