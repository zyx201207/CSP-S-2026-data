#include<bits/stdc++.h>
using namespace std;
long long a[200020];
long long b1(long long x)
{
    long long s=0;
    while(x)
    {
        s+=x%2;
        x/=2;
    }
    return s;
}
bool cmp(long long x,long long y)
{
    if(b1(x)!=b1(y))
        return b1(x)>b1(y);
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ans;
    cin>>n>>m;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    if(m==1)
    {
        cout<<a[0];
        return 0;
    }
    ans=a[0]&a[1];
    for(long long i=2;i<m;i++)
        ans&=a[i];
    cout<<ans;
    return 0;
}
