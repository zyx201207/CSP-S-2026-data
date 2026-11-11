#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200010],max1=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>max1)
            max1=a[i];
    }
    if(m==1)
    {
        cout<<max1;
        return 0;
    }
    max1=-1;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((a[i]&a[j])>max1)
                {
                    max1=a[i]&a[j];
                }
            }
        }
        cout<<max1;
        return 0;
    }
    max1=-1;
    if(m==3)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if((a[i]&a[j]&a[k])>max1)
                    {
                        max1=a[i]&a[j]&a[k];
                    }
                }
            }
        }
        cout<<max1;
        return 0;
    }
    max1=-1;
    if(m==4)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        if((a[i]&a[j]&a[k]&a[l])>max1)
                        {
                            max1=a[i]&a[j]&a[k]&a[l];
                        }
                    }
                }
            }
        }
        cout<<max1;
        return 0;
    }
    max1=-1;
    if(m==5)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        for(int mn=l+1;mn<=n;mn++)
                        {
                            if((a[i]&a[j]&a[k]&a[l]&a[mn])>max1)
                            {
                                max1=a[i]&a[j]&a[k]&a[l]&a[mn];
                            }
                        }
                    }
                }
            }
        }
        cout<<max1;
        return 0;
    }
    cout<<"0";
    return 0;
}
