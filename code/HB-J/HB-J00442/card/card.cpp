#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    bool y=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]<=a[i]) y=1;
        else y=0;
    }
    if(y) for(int i=1;i<=m;i++) cout<<i;
    return 0;
}
