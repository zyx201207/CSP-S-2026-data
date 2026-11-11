#include<bits/stdc++.h>
using namespace std;
char s[200005];
long long a[200005],n,k=0;
long long sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
        sum+=a[i];
    }
    sum/=2;
    long long ans=0,o=a[1],l=sum,g=n;
    for(int i=1;i<=n;i++)
    {
        sum-=a[i];
        if(sum<0)
        {
            k=i;
            break;
        }
        if(sum==0)
        {
            k=i+1;
            break;
        }
    }
    for(int i=1;i<=k&&g>=k;i)
    {
        int j=a[i];
        if(s[i]!=s[g])
        {
            ans+=min(a[i],a[g]);
            a[i]-=a[g];
        }
        if(a[i]<=0)
        {
            a[g]-=j;
            i++;
        }
        else
        {
            g--;
        }
    }
    cout<<ans;

    return 0;
}
