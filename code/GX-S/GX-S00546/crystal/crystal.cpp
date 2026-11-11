#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long i,l=1,ans=1,a[500005];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(i=2;i<=n;i++)
    {
        m-=((i-l)*(a[i]-a[i-1]));
        while(m<0)
        {
            m+=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}

