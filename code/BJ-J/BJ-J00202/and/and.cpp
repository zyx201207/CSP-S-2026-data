#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0,sum=0;
bool cmp(int a,int b)
{
    return a>b;
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
    ans=a[m];
    for(int i=m;i>1;i--)
    {
        ans=ans&a[i-1];
    }
    cout<<ans;
    return 0;
}
