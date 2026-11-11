#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long sum;
    for(long long i=n;i>n-m;i--)
    {
        if(i==n)
        {
            sum=a[i];
            continue;
        }
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
