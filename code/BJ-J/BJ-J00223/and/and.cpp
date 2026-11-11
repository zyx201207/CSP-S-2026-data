#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[500005]={},x=(1ll<<31)-1;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        int nx=x;
        for(int j=1;j<=n;j++)
            nx=max(nx,x&a[j]);
        x=nx;
    }printf("%d",x);
    return 0;
}
