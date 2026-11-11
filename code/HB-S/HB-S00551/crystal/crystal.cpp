#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans[500005];
long long b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
/*    for(int i=1;i<=n;i++)
        b[i]=a[i]-a[i-1]+b[i-1];*/
    long long sum=m;
    int mid=n/2;
    for(int i=mid;i<=n;i++)
        ans[i]=1;
/*    for(int i=1;i<=n;i++)
        cout<<"cazhi="<<b[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(b[i]-b[j]<=m&&(b[i]-b[j+1]>m||b[i+1]-b[j]>m))
            {
                cout<<i-j+1<<endl;
                return 0;
            }
        }
    }*/
    for(;mid<=n;mid++)
    {
        for(int i=mid-1;i>=1;i--)
        {
            if(a[mid]-a[i]<=sum)
            {
                sum-=a[mid]-a[i];
                ans[mid]++;
            }
            else
                break;
        }
        sum=m;
    }
    long long cnt=ans[n/2];
    for(int i=n/2+1;i<=n;i++)
        cnt=max(cnt,ans[i]);
    cout<<cnt<<endl;
    return 0;
}