#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    freopen("subwsy.in","r",stdin);
    freopen("subwsy.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<2;j++)
        {
            if(a[j]<a[j+1])
            {
                a[j]++;
            }
            else if(a[j+1]<a[j+2])
            {
                a[j+1]++;
            }
        }

    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[1])
            cnt++;
    }

    cout<<cnt;
    return 0;
}
