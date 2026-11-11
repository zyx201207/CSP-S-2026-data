#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long maxn,mini=1000000000000;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int d=a[2]-a[1];
    int ans=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        ans=ans+2*i;
        if(ans>m)
        {
            sum=i-1;
            break;
        }
    }
    cout<<sum;
    return 0;
}
