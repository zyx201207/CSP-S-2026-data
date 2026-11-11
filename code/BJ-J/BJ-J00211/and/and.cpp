#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[200005];
long long sum[200005];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    sum[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        sum[i]=(sum[i-1]&a[i]);
        //cout<<sum[i]<<"\n";
    }
    //cout<<endl;
    long long maxn=0;
    for(int i=1;i<=n-m+1;i++)
    {
        maxn=max(maxn,sum[i]&a[i+m-1]);
        //cout<<maxn<<"\n";
    }
    cout<<maxn;
    return 0;
}

