#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        sort(a,a+n);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        int n[10005];
        for(int i=0;i<n;i++)
        {
            sort(a,a+n);
            cout<<a[n];
            return 0;
        }
    }
    else
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {

            ans+=a[n-i];

        }
        cout<<ans;
        return 0;
    }
}
