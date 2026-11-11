#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(long long x,long long y)
{
    return x>y;
}
bool cmp1(long long x)
{
    while(x%2==0)
    {
        x/=2;
    }
    if(x==1)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[200001];
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long cnt=a[0];
    long long i=0;
    while(m--)
    {
        cnt=cnt&a[i];
        i++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
