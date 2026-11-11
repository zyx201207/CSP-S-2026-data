#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
if(n<=5000){
    long long ans=-1e20;
    for(int i=1;i<=n;i++)
    {
        long long l=m;
        long long cnt=0;
        for(int j=i;j>=1;j--)
        {
            if(l<a[i]-a[j])
            {
                break;
            }
            cnt++;
            l=l-(a[i]-a[j]);
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
if(abs(a[1])<=100||abs(a[n])<=100)
{
 /*   int box[250]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i=1;i<=n;i++)
        box[a[i]+105]++;
    int cnt=0;
    for(int i=5;i<=205;i++)
        for(int j=1;j<=box[i];j++)
            a[++cnt]=i-105;*/
    long long ans=-1e20;
    for(int x=-100;x<=100;x++)
    {
        int z=1,y=n;
        while(z<y)
        {
            int mid=(z+y)/2+1;
            if(a[mid]>=x)
            {
                y=mid;
            }
            else
            {
                z=mid;
            }
        }
        long long l=m;
        long long cnt=0;
        for(int j=z;j>=1;j--)
        {
            if(l<x-a[j])
            {
                break;
            }
            cnt++;
            l=l-(x-a[j]);
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
    m/=a[2]-a[1];
    int ans;
    for(int i=1;i<=n;i++)
    {
        if(m<i)
        {
            cout<<i<<endl;
            return 0;
        }
        m-=i;
    }
    cout<<n<<endl;
    return 0;
}
