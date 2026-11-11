#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[1000005],ans;
bool cmp(long long a,long long b)
{
    return a>=b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
