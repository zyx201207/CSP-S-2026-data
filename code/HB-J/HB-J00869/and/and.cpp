#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,a[100000000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long ak=-1;
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]>ak)
            {
                ak=a[i];
            }
        }
        cout<<ak;
        return 0;
    }
    else if(n==m)
    {
        ak=a[0];
        for(int i=1;i<n;i++)
        {
            ak&=a[i];
        }
        cout<<ak;
        return 0;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
