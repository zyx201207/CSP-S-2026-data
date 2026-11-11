#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010],vis[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]) vis[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}
