#include<bits/stdc++.h>
using namespace std;
long a[500005],c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum=0,max_v=-1,flag=1;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i]-a[i-1];
    }
    for(int i=3;i<=n;i++)
        if(c[i]!=c[i-1]){flag=0;break;}
    if(flag==1)
    {
        int k=1;
        while(1+1==2)
        {
            if(m-c[2]*k<0){cout<<k;return 0;}
            m-=c[2]*k;
            k++;
        }
        cout<<k;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)
    {
        long long t=m,x=i-1;
        for(int j=i-1;j>=1;j--)
        {
            if(t-a[i]+a[j]<0)
            {
                x=i-j-1;
                break;
            }
            else t=t-a[i]+a[j];
        }
        max_v=max(x,max_v);
    }
    cout<<max_v+1;
    return 0;
}
