#include<iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    int m,n,a[202600]s=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        for(int i=0;i<n;i++)
        {
            s=max(s,a[i]);
        }
    }
    else if(m==n)
    {
        s=a[0];
        for(int i=1;i<=1;i++)
        {
            s=s&a[i];
        }
    }
    else if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n,i++)
            {
                s=max(s,a[i]&a[j]);
            }
        }
    }
    else if(m==n-1)
    {
        for(int i=0;i<n;i++)
        {
            int ss;
            if(i==0)
            {
                ss=a[1];
                for(int j=2;j<n;j++)
                {
                    ss=ss&a[j];
                }
            }
            else
            {
                ss=a[0];
                for(int j=1;j<n;j++)
                {
                    if(j!=i)
                    {
                        ss=ss&a[i];
                    }
                }
            }
            s=max(s,ss);
        }
    }
    return 0;
}

