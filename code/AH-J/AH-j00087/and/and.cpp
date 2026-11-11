#include<bits/stdc++.h>

int n,m,a[200005],maxn;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }

    std::sort(a+1,a+n+1,cmp);

    maxn=a[1];
    for(int i=2;i<=m;i++){
        maxn=maxn & a[i];
    }

    std::cout<<maxn;
return 0;
}
