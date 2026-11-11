#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000005],sum,maxx=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1)
    {
        cout<<maxx;
        return 0;
    }
    sort(a+1,a+n+1);
    sum=a[n];
    for(int i=n-1;i>=n-m+1;i--)
    {
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
