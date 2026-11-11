#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
bool cmp(int a,int b)
{
    if(a>b)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i = 1;i<m;i++)
    {
        ans=a[i]&a[i+1];
    }
    cout<<ans;
    return 0;
}
