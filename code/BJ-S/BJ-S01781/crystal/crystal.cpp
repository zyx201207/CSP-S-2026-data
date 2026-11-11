#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[120000005],b[120000005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int t=2*m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i]+b[i-1];
        cnt++;
        if(abs(b[i])>t)
        {
            break;
        }
    }
    cout<<cnt-1;
    return 0;
}
