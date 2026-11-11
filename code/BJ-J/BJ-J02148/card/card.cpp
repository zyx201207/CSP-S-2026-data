#include<bits/stdc++.h>
int a[500005];
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i+1])
        {
            s=1;
        }
    }
    if(s==0)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<n-1;
        }
    }
    return 0;
}
