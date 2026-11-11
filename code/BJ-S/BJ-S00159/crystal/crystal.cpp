#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[500010],b[500010],c[500010];
double x1,x2;
int ans1,ans2;
int sum;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x1+=(1.0*(a[i])/n);
        x2+=(1.0*(a[i])/n);
    }
    //cout<<x1<<" "<<x2<<endl;
    x1=floor(x1);
    x2=ceil(x2);
    for(int i=1;i<=n;i++)
        b[i]=abs(a[i]-x1);
    for(int i=1;i<=n;i++)
        c[i]=abs(a[i]-x2);
    sort(b+1,b+n+1);
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++)
    {
        //cout<<b[i]<<" ";
        if((sum+b[i])>m)
        {
            ans1=i-1;
            break;
        }
        sum+=b[i];
    }
    //cout<<sum<<endl;
    //cout<<endl;
    sum=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<c[i]<<" ";
        if((sum+c[i])>m)
        {
            ans2=i-1;
            break;
        }
        sum+=c[i];
    }
    //cout<<sum<<endl<<ans1<<" "<<ans2<<" ";
    cout<<max(ans1,ans2);
    return 0;
}
