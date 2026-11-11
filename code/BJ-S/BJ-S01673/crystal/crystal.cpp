#include <bits/stdc++.h>
using namespace std;
long long n,m,x=1,y=1,ans=0,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
        {
            y+=1;
        }
        else if(y>=x)
        {
            x=y;
            y=1;
        }
        else
        {
            y=1;
        }
    }//tongjixiangtongzuiduodeshuliang
    if(m==0)
    {
        cout<<x;
        return 0;
    }
    long long op=1;
    while(op==1)
    {
        long long bnm=10000;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]!=a[i]&&a[j]-a[i]<bnm&&a[j]-a[i]>0)
                {
                    bnm=a[i]-a[j];
                }
            }
        }
        if(m-bnm<0)
        {
            op=0;
        }
        else
        {
            m-=bnm;
            ans+=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]-a[i]==bnm)
                {
                    a[i]=a[j];
                }
            }
        }
    }
    cout<<ans;
}