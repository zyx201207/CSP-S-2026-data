#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        if(a[i]!=a[i+1])
        {
            cout<<i<<" ";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
