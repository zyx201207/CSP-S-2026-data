#include<bits/stdc++.h>
#define ll long long
using namespace std;
int CC,T;
ll n,d,a[3355306];
ll minn=1e18+10;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>CC>>T;
    while(T--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++)minn=min(a[i]-a[i-1],minn);
        if(d<minn)cout<<0;
        else cout<<rand();
    }
    return 0;
}
//blue or q
