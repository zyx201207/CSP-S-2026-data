#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn1=-1,maxn2,ans;
int a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn1=max(maxn1,a[i]);
    }
    if(m==1)
    {
        cout<<maxn1;
    }
    else if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
                maxn2=max(maxn2,a[i]&a[j]);
        }
        cout<<maxn2;
    }
    else if(m==n)
    {
        ans=a[1]&a[2];
        for(int i=3;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else
    {
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }
    return 0;
}
