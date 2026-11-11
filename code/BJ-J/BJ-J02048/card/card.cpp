#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]+=m;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
return 0;
}