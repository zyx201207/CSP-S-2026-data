#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[1];
        return 0;
    }
    long long maxa=0,maxi1,maxi2;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]&a[j]>maxa)
            {
                maxa=a[i]&a[j];
                maxi1=i,maxi2=j;
            }
        }
    }
    a[maxi1]=-1,a[maxi2]=-1,m-=2;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)continue;
        if(m==0)break;

        long long x=maxa;
        maxa=x&a[i],maxi1=i;

        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==-1)continue;
            if(x&a[j]>maxa)
            {
                maxa=x&a[j];
                maxi1=j;
            }
        }

        a[maxi1]=-1;
        m--;
    }
    cout<<maxa;
    return 0;
}

