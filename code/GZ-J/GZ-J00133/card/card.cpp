#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,k;
    cin>>n;
    for(int i=n;i<=n-1;i++)
    {
        if(n!=k)
        {
            cout<<n;
        }
        else
        {
            cout<<n*0<<n;
        }
    }
}
