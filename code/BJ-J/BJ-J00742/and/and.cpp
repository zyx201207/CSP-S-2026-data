#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool cmp(int x,int y)
{
    return x>y;
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
    long long cnt=a[1];
    for(int i=2;i<=m;i++)
    {
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}

