#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,i,cnt=0,dlt;
    bool fl=true;
    cin>>n>>m;
    long long a[n+3];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==1)dlt=a[1]-a[0];
        if(i>=2&&(a[i]-a[i-1])!=dlt)fl=false;
    }
    if(fl)
    {
        while(m>=0)
        {
            cnt++;
            m-=cnt*dlt;
        }
        cout<<cnt;
        return 0;
    }
    sort(a,a+n);
    long long b[2*n];
    memset(b,0,sizeof(b));
    for(i=0;i<n-1;i++)
    {
        b[i]=a[i+1]-a[i];
    }
    long long s=b[0],s0=b[0],sm=1e18,st=0;
    cnt=0;
    if(s<=m){
        sm=s;
        cnt++;
    }
    for(i=1;i<n;i++)
    {
        s=s-s0+cnt*b[i+cnt-1];
        s0=s0-b[i-1]+b[i+cnt-1];
        if(i==st+cnt&&sm+(cnt+1)*b[i]<=m)
        {
            cnt++;
            sm=sm+(cnt)*b[i];
            s+=cnt*b[i+cnt-1];
            s0+=b[i+cnt-1];
        }
        else if(s<=sm)
        {
            st=i;
            sm=s;
        }
    }
    cout<<cnt+1;
    return 0;
}
