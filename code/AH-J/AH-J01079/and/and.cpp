#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long zh,big=-1;
    cin>>a[1];
    zh=a[1];
    big=max(big,a[1]);
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        big=max(a[i],big);
        zh&=a[i];
    }
    if(m==1)
    {
        cout<<big;
        return 0;
    }
    if(m==n)
    {
        cout<<zh;
        return 0;
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        for(int k=i+1;k<=n;k++)
        {
            ans=max(a[i]&=a[k],ans);
        }
    }
    cout<<ans;
}
