#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005]={0},sum;
int cmp(long long x,long long y)
{
    return x>=y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    sum=a[1];
    for(long long i=2;i<=m;i++)
        sum=sum&a[i];
    cout<<sum;
    return 0;
}
