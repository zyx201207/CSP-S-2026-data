#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1;
int a[500005];
long long t[500005],x[500005];
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
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt;j++)
        {
            t[i]+=a[j];
        }
        x[i]=(t[i]+m)/cnt;
        if(x[i]<a[cnt])
        {
            cout<<cnt-1;
            return 0;
        }
        cnt++;
    }
    cout<<n;
    return 0;
}
