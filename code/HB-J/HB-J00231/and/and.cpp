#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,i,j,ans=0;
    cin>>n>>m;
    int a[n+2];
    if(m==n)
    {
        cin>>a[0];
        j=a[0];
        for(i=1;i<n;i++)
        {
            cin>>a[i];
            j=j&a[i];
        }
        cout<<j;
        return 0;
    }
    for(i=0;i<n;i++) cin>>a[i];
    if(n<2001&&m==1)
    {
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(n<2001&&m==2)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j) ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    sort(a,a+n);
    cout<<a[n-m];
    return 0;
}
