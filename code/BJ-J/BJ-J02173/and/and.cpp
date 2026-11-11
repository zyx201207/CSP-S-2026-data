#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    ll mx=0,res=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
        res=res&a[i];
    }
    //sort(a+1,a+n+1);
    //reverse(a+1,a+n+1);
    if(m==1)
    {
        cout<<mx;
        return 0;
    }
    if(m==n)
    {
        cout<<res;
        return 0;
    }
    if(m==2)
    {
        ll mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                mx=max(mx,a[i]&a[j]);
                //cout<<a[i]<<" "<<a[j]<<" "<<(a[i]&a[j])<<" ";
            }
        }
        cout<<mx;
        return 0;
    }
    return 0;
}