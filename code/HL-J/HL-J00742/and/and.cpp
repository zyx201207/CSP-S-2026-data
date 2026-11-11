#include<bits/stdc++.h>
using namespace std;
int a[200002];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(m==2)
    {
        long long b=LONG_LONG_MAX;
        while(b>a[n-1])
            b/=2;
        //cout<<b<<'\n';
        for(int i=n;i>0;i--)
            if(a[i]<b)
            {
                cout<<a[i];
                return 0;
            }
    }
    cout<<a[n-m+1];

    return 0;
}
