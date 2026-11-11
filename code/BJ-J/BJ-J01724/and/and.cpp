#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
