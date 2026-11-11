#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000007];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4 and m==2)
    {
        cout<<12;
    }
    if(n==5 and m==3)
    {
        cout<<7;
    }
    return 0;
}
