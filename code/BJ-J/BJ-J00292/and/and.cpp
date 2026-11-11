#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans1,ans2,ans;
void w(int num,int lst,int nans)
{
    if(num==m)
    {
        ans=max(ans,nans);
        return;
    }
    for(int i=lst+1;i<=n-m+num+1;i++)
    {
        w(num+1,i,nans&a[i]);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans1=max(a[i],ans1);
        ans2=ans2&a[i];
    }
    if(m==1)
    {
        cout<<ans1;
        return 0;
    }
    if(m==n)
    {
        cout<<ans2;
        return 0;
    }
    for(int i=1;i<=n-m+1;i++)
    {
        w(1,i,a[i]);
    }
    cout<<ans;
    return 0;
}
