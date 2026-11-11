#include<bits/stdc++.h>
using namespace std;
long long a[500001],q[500001];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q[i]=q[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        long long f=(a[i]*(i-1)-q[i-1]);
        if(f>m)
        {
            cout<<i-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
