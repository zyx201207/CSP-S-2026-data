#include<bits/stdc++.h>
using namespace std;
int n,m;
int const N=2e5+10;
int a[N];
long long y=-1;
void ss(long long s,int k,long long nd,int i){
    nd=nd&s;
    if(k>=m){
        y=max(y,nd);
        return;
    }
    k++;
    for(int j=i+1;j<=n;j++){
        ss(a[j],k,nd,j);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        ss(a[i],1,a[i],i);
    }
    printf("%lld",y);
}
