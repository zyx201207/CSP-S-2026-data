#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int nowc,lastc,dc=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    lastc=a[2]-a[1];
    for(int i=2;i<=n;i++)
    {
        nowc=a[i]-a[i-1];
        if(lastc!=nowc)
        {
            dc=0;
            break;
        }
        lastc=nowc;
    }
    if(dc==1)
    {
        long long an=1,hf=lastc;
        while(hf<=m)
        {
            an++;
            hf+=hf+lastc;
        }
        cout<<an;
        return 0;
    }
    b[1]=0,b[2]=a[2]-a[1];
    for(int i=3;i<=n;i++)
    {
        b[i]=(i-1)*(a[i]-a[i-1])+b[i-1];
    }
    long long ms=0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if(a[j]-a[i]<=m)
            {
                ms=max(j-i+1,ms);
            }
        }
    }
    cout<<ms;
    return 0;
}
