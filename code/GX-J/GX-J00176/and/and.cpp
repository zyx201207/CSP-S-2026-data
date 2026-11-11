#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000],s;
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int b=0;b<n;b++)
    {
        cin>>a[b];
    }
    sort(a,a+n,cmp);
    s=a[0];
    for(int b=1;b<m;b++)
    {
        s&=a[b];
    }
    cout<<s;
    return 0;
}
