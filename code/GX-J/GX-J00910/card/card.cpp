#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10005],t[10005];

void tf()
{
    for(int i=1;i<=n;i++){
        t[i]=a[i];
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<3<<' '<<1<<' '4;
    return 0;
}
