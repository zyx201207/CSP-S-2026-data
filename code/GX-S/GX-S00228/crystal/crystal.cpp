#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[100010],biff[100010];
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal,out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        biff[i]=a[i]+a[i-1];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        long long cnt=(biff[i]+m)/i;
        if(cnt*i==biff[i])
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
