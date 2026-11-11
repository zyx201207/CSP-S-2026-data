#include<bits/stdc++.h>
using namespace std;
long long a[200002];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    long long b=0;
    for(int i=1;i<=m;i++)
    {

        b+=a[i];
        cout<<b<<' ';
    }

    return 0;
}
