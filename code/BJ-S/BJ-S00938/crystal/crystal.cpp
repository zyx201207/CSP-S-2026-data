#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=1e18;
int n,ans;
long long m,a[N],c[N],s[N];
bool check(int len)
{
    long long t=INF,sum=0;
    int r;
    for(int i=len;i<n;i++)
        if(s[i]-s[i-len]<t)r=i,t=s[i]-s[i-len];
    for(int i=r-len+1;i<=r;i++)
        sum+=s[r]-s[i-1];
    if(sum<=m)return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        c[i-1]=a[i]-a[i-1];
    for(int i=1;i<n;i++)
        s[i]=s[i-1]+c[i]/*,cout<<s[i]<<" "*/;
    /*cout<<"\n";*/
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(check(mid-1))ans=max(ans,mid),l=mid+1;
        else r=mid-1;
        //cout<<l<<" "<<r<<" "<<mid<<"\n";
    }
    printf("%d",ans);
    return 0;
    fclose(stdin);
    fclose(stdout);
}
