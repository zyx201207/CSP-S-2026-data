#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long k,num1,num2,maxx1,maxx2,maxx;
int D(int x)
{
    for(int i=1;i<=x;i++)
    {
        num2=num1;
        num1=maxx2&a[x-i];
        num1=max(num1,num2);
    }
    maxx1=num1;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    maxx=a[n];
    for(int i=n;i>=0;i--)
    {
        for(int j=1;j<=m;i++)
        {
            D(i);
            maxx2=max(maxx1,maxx2);
        }
        maxx=max(maxx,maxx2);
    }
    cout<<maxx;
}
