#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500005];
int dx[500005];
long long dy[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    dx[1]=0;
    dy[1]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        dx[i]=a[i]-a[i-1];
        dy[i]=dy[i-1]+dx[i]*(i-1);
    }
    for(int i=n;i>=1;i--)
    {
        if(m>=dy[i])
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
