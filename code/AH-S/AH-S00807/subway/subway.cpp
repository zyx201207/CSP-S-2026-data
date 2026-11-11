#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int c,n,m,d,q;
int w[N]={},k[N]={};
int a[N][N]={},t[N][N]={};
int f(int x,int y){
    int ans=w[x]+w[y];
    for(int i=1;i<=y;i++){
        for(int j=1;j<=i;j++) ans+=t[i][j];
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
        }
    }
    while(q--){
        int x,y;
        scnaf("%d%d",&x,&y);
        cout<<f(x,y)<<endl;
    }
    return 0;
}
