#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],b[600000],t,k=123456789,c=0,d=0,e[600000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==a[j+1])
            {
                a[j]+=a[j+1];
                for(int l=j;l<=n;l++)
                    a[l-1]=a[l];
                n--;
                c++;
                for(int i=2;i<=n;i++)
                    b[i]=a[i]-a[i-1];
                break;
            }
        }
        if(c>d)
        {
            d=c;
            continue;
        }
        if(c==d)
        {
            for(int i=2;i<=n;i++)
            {
                if(b[i]<k)
                {
                    k=b[i];
                }
            }
            for(int i=2;i<=n;i++)
            {
                if(b[i]==k)
                {
                    k=123456789;
                    a[i-1]++;
                    b[i]--;
                }
            }
        }
    }
    c--;
    cout<<c;
    return 0;
}
