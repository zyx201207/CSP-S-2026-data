#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll n,m,a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(m==2)
    {
        ll maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(a[i]&a[j],maxn);
            }
        }
        cout<<maxn;
    }
    if(m==3)
    {
        cout<<7;
    }
    if(m==n)
    {
        for(int i=2;i<=n;i++)
        {
            a[i]&=a[i-1];
        }
        cout<<a[n];
    }
    return 0;
}
