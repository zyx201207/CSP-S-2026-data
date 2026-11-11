#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],m,ans=0,d=0;
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
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {

        ans=a[i];
        for(int j=i+1;j<=m;j++)
        {
            ans=ans and a[j+1];

        }
        d=max(ans,d);
    }
    cout<<d;
    return 0;
}


