#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(n==m) b[a[i]]=i;
        else b[i]=a[i];
    }
    if(n==m){
        for(int i=1;i<=n;i++) cout<<b[i]<<" ";
        return 0;
    }
    return 0;
}
