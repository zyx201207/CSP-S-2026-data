#include<bits/stdc++.h>
using namespace std;
long long c2,t,n,d,a[2000100],b[2000100],c[2000100],d2[2000100],ans,e[2000100],f[2000100],g[2000100];
long long findd(long long i)
{
    long long l=1,r=i,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[i]-a[mid]>d)l=mid+1;
        else r=mid;
    }
    return r;
}
long long find2(long long i)
{
    long long l=i,r=n,mid;
    while(l<r)
    {
        mid=(l+r+1)/2;
        if(a[mid]-a[i]>d)r=mid-1;
        else l=mid;
    }
    return l;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c2>>t;
    while(t--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=0;
            c[i]=0;
            d2[i]=0;
            e[i]=0;
            f[i]=0;
            g[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            long long p=find2(i);
            if(p!=n)
            {
                long long q=find2(p);
                if(q==find2(p-1)&&q!=find2(p-2))
                {
                    b[i]=q;
                    c[q]=1;
                }
            }
            d2[i]=p;
            e[i]=findd(i);
 //           cout<<b[i]<<" "<<c[i]<<" "<<d2[i]<<" "<<e[i]<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            if(e[i]==i)
            {
                f[i]=i-1;
            }
            else if(b[i-1]!=0)
            {
                f[i]=i-1;
            }
            else f[i]=f[i-1];
     //       cout<<f[i]<<" ";
        }
    //    cout<<endl;
        for(int i=n;i>=1;i--)
        {
            if(d2[i]==i)
            {
                g[i]=i+1;
            }
            else if(c[i+1]!=0)
            {
                g[i]=d2[i];
            }
            else g[i]=g[i+1];
    //        cout<<g[i]<<" ";
        }
    //    cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(b[i]!=0)
            {
                ans+=(i-f[i])*(g[d2[i]+1]-d2[i]-1);
      //          cout<<ans<<" ";
            }
        }
        cout<<ans<<endl;
    }
}