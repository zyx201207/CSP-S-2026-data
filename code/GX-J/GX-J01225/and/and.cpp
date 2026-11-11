#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long max_sum=a[1];
    for(int i=2;i<=m;i++)
    {
        max_sum=max_sum&a[i];
    }
    cout<<max_sum;
    return 0;
}
