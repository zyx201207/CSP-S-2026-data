#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);

    int n,m;
    cin>>n>>m;
    int s=0;
    int t=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[n/2]==a[i])
            t++;
    }
    for(int i=0;i<n;i++)
    {
            m=m-(a[n/2]-a[i]);
            s++;
            if(m==0)
            break;
    }
    cout<<s+t;
    return 0;
}
