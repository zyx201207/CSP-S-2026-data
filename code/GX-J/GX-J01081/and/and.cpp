#include<bits/stdc++.h>
using namespace std;
struct num
{
    long long v;
    long long cnt0;
}a[200001];
bool cmp(num x,num y)
{
    if(x.cnt0!=y.cnt0) return x.cnt0>y.cnt0;
    return x.v>y.v;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].v;
        a[i].cnt0=__builtin_popcountll(a[i].v);
    }
    sort(a+1,a+1+n,cmp);
    long long ans=a[1].v;
    for(int i=2;i<=m;i++)
    {
        ans&=a[i].v;
    }
    cout<<ans;
    return 0;
}
