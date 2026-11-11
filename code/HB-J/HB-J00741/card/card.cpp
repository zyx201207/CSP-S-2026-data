#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main()
{
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<=m;j++) b[j]++;
    }
    for(int i=1;i<=m;i++) cout<<b[i];
    return 0;
}
