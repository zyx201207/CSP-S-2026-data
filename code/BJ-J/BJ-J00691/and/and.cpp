#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(long long x,long long y)
{
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    cout<<a[m];
    return 0;
}