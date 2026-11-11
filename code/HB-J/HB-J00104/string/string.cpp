#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a[200005],c[200005];
    long long n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int j=1; j<=m; j++)
    {
        cin>>c[j];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {

            if(c[j]==c[j-1]==c[j+1])
                cout<<0;
            else if(a[i]==a[i-1]==a[i+1])
                cout<<a[i];
        }
        break;
    }
    return 0;
}
