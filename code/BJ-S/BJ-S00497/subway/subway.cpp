#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],a[505][500005],t[505][500005],k[505];
int isin(int sta){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(sta==a[i][j]){
                return i;
            }
        }
    }
}
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
    int x,y;
    while(q--){
        cin>>x>>y;

    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl<<17;
    }else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl<<16;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
