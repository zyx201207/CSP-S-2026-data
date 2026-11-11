#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[500010],c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    /*for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

        }
    }*/
    for(int i=1;i<=m;i++){
        if(i%2==0)cout<<i;
        else cout<<i+1;
    }
    return 0;
}
