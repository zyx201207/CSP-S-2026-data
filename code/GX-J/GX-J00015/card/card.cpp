#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
bool x=0;
int main()
{
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=i;j<=n;j++)
        {
            if(a[j]==a[i])
                x=1;

        }
    }
    for(int i=n;i>n-2;i--)
        cout<<a[i]<<" ";
    cout<<m;
    return 0;
}
