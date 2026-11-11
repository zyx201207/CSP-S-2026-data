#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main()
{
    freopen("crystal.in","r","stdin");
    freopen("crystal.out","w","stdout");
    ll n,m,sum=0,ans;
    cin>>n>>m;
    for(ll i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i = 1;i <= n;i++)
    {
        sum+=a[i];
        ll num=a[i]*i-sum;
        if(num<=m)
        {
            ans=i;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
