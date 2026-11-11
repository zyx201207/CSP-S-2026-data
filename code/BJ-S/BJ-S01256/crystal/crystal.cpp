#include<bits/stdc++.h>
using namespace std;
const int N = 5*10e5+10;
long long n,m,a[N],ans=0,cnt,k;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(long long i=1;i<=n;i++)
    {
        k=0;
        cnt=0;
        for(long long j=0;j<=i;j++)
        {
            k+=a[i]-a[j];
            cnt++;
        }
        if(k>m)
        {
            break;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
