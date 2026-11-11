#include <bits/stdc++.h>
using namespace std;


bool cmp(int b,int c)
{
    return b>c;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,ma=0;
    cin>>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}
