#include<bits/stdc++.h>
using namespace std;

int n,m,p,h;
int a[500009],b[300009];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << noboolalpha;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        h=a[i];
        b[h]++;
    }
    if(a[1]==a[n-1])
    {
        h=a[1];
        b[h]=n-1;
    }
    p=a[n];
    b[p]=n;
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }

    return 0;
}
