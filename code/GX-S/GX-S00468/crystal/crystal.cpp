#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
typedef long long ll;
int n;
ll m,sum[N],a[N],ans=1;
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
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1;
    for(int i=2;i<=n;i++)
    {
        while((sum[i]-sum[l-1]-(a[i]*(ll)(i-l+1))+m)<0)
        {
            l++;
        }
        ans=max(ans,(ll)(i-l+1));
    }
    cout<<ans;
    return 0;
}
