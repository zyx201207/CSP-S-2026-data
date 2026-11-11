#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],tot=1;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=n-1;i>=1;i--)
    {

        if(a[i]==a[i+1])
        {
            tot++;
        }
        else
        {
            tot=1;
        }
        if(tot==m)
        {
            cout<<a[i];
            break;
        }

    }
    return 0;
}

