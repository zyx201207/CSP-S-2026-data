#include<bits/stdc++.h>
using namespace std;
int a[500005];
int z[500005];
int f[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];


    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
       z[a[i]]++;
       for(int i=1;i<=n;i++)
    {
       if(z[a[i]]!=0)
       {
           f[a[i]]++;
       }
    }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<f[i]<<" ";
    }
    return 0;

}

