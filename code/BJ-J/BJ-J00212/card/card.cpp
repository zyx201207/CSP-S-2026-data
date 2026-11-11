#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)a[0]=a[i];
        if(a[i]!=a[i-1])cout<<i-1<<' ';
    }
    cout<<n;
    return 0;
}
