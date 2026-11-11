#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long last=0;
    long long sum=0;
    long long id=1;
    for(long long i=1;i<=n;i++)
    {
        last=abs(a[i]-a[i-1])*(i-1)+last;
        if(last<=m)
        {
            id=i;
        }
    }
    cout<<id<<endl;
    return 0;
}
