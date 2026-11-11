#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],l=1,r=1,ans,sum=1,ans2=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(1+a,a+n+1);
    for(int i=2;i<=n;i++)
    {
        m-=sum*(a[i]-a[i-1]);
        while(m<0)
        {
            sum--;
            m+=a[i]-a[l];
            l++;
        }
        sum++;
        ans2=max(ans2,sum);
    }
    cout<<ans2;
}