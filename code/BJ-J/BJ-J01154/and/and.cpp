#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(),cin.tie(),cout.tie();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll cnt=2,ans=a[n]&a[n-1];
    for(int i=n-2;i>=1;i--)
    {
        cnt++;
        if(cnt>m)
        {
            break;
        }
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
