#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],s[500005],u,sum[500005],b[500005];
int n,v=1,ans;
bool f1=true,f2=true;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(f1&&a[i]!=i)f1=false;
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        s[i]=a[i]-a[i-1],b[i]=b[i-1]+s[i];
        if(f2&&i>2&&s[i]!=s[i-1])f2=false;
    }
    if(f1||f2)
    {
        long long l=1,r=10000000000,mid,midd,an,ch=a[2]-a[1];
        while(l<=r)
        {
            mid=(l+r)/2,midd=mid*(2+ch*(mid-1))/2;
            if(midd==m)
            {
                an=mid;
                break;
            }
            if(midd>m)r=mid-1;
            else an=mid,l=mid+1;
        }
        if(an<n)printf("%lld",an+1);
        else printf("%lld",n);
        return 0;
    }
    while(sum[v]<=m)
    {
        sum[v+1]=s[v+1]*v+sum[v];
        v++;
    }
    v--,ans=v,u=m-sum[v];
    int l=1;
    for(int i=v+1;i<=n;i++)
    {
        while(u<s[i]*(i-l))u+=b[i-1]-b[l],l++;
        ans=max(ans,v-l+1);
    }
    cout<<ans;
    return 0;
}
