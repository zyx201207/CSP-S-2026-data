#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],sum,ans;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(sum%2==0)
    {
        ll st1,st2,cnt=0,mid=sum/2;
        for(int i=1;i<=n;++i)
        {
            if(cnt+a[i]>=mid)
            {
                st1=i;
                st2=mid-cnt;
                break;
            }
            cnt+=a[i];
        }
        ll i1=st1,i2=st2,j1,j2,no=mid;
        if(i2==a[i1])j1=st1+1,j2=1;
        else j1=st1,j2=st2+1;
        while(no)
        {
            no--;
            if(c[i1]!=c[j1])ans++;
            if(i2==1)i2=a[i1-1],i1--;
            else i2--;
            if(j2==a[j1])j1++,j2=1;
            else j2++;
        }
        cout<<ans<<endl;
    }
    else
    {
        ll st1,st2,cnt=0,mid=sum/2+1;
        for(int i=1;i<=n;++i)
        {
            if(cnt+a[i]>=mid)
            {
                st1=i;
                st2=mid-cnt;
                break;
            }
            cnt+=a[i];
        }
        ll i1=st1,i2=st2,j1=st1,j2=st2,no=mid;
        while(no)
        {
            no--;
            if(i1==0||j1==n+1)break;
            if(c[i1]!=c[j1])ans++;
            if(i2==1)i2=a[i1-1],i1--;
            else i2--;
            if(j2==a[j1])j1++,j2=1;
            else j2++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
