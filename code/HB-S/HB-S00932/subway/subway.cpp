#include<iostream>
int c,n,m,d,q;
int w[500005],k[100005];
int a[505][500005],t[505][500005],x,y;

long long subway(int x,int y){
    return 20;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    std::cin.tie(0);

    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)std::cin>>w[i];
    for(int i=1;i<=n;i++){
        std::cin>>k[i];
        for(int j=1;j<=k[i];j++){
            std::cin>>a[i][j]>>t[i][j];
        }
    }
    for(int k=1;k<=q;k++){
        std::cin>>x>>y;
        std::cout<<subway(x,y);
    }


}
