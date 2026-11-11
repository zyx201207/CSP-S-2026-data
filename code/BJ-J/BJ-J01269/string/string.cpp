#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int64_t sum=0,ans=0;
    int n;
    cin>>n;
    int64_t a[n+5];
    int b[n+5];
    a[0]=0;
    b[0]=100000;
    for(int i=1;i<=n;i++)
    {
        char xx;
        cin>>a[i]>>xx;
        b[i]=int(xx);
        if(b[i]==b[i-1])
        {
            a[i-1]=a[i]+a[i-1];
            b[i-1]=b[i];
            i--;n--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
    }
    if(n==1) {cout<<"0"<<endl;return 0;}
    int64_t mid,mid2,qmid;
    if(sum%2==0)
    {
        mid=sum/2;
        qmid=sum/2;
    }
    else
    {
        mid=sum/2+1;
        qmid=sum/2;
    }
    mid2=mid;
    int ans1,ans2;
    for(int i=1;i<=n;i++)
    {
        if(mid-a[i]>0)
        {
            mid-=a[i];
        }
        else
        {
            ans1=mid;
            ans2=a[i]-mid;
            ans=qmid-min(ans1,ans2);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
