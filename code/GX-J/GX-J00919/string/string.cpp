#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long f=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    long long i=1;
    long long j=n;
    if(n%2==1)
    {
        while(1)
        {
            if(c[i]!=c[j])
            {
                f=f+min(a[i],a[j]);
                a[i]=a[i]-min(a[i],a[j]);
                a[j]=a[j]-min(a[i],a[j]);
            }
            else
            {
                a[i]=a[i]-min(a[i],a[j]);
                a[j]=a[j]-min(a[i],a[j]);
            }
            if(a[i]==0)
            {
                i++;
            }
            if(a[j]==0)
            {
                j--;
            }
            if(i==n/2+1&&a[i+1]==0&&a[i-1]==0
               ||j==n/2+1&&a[j+1]==0&&a[j-1]==0)
            {
                    break;
            }
        }

    }
    else
    {
        while(1)
        {
            if(c[i]!=c[j])
            {
                f=f+min(a[i],a[j]);
                a[i]=a[i]-min(a[i],a[j]);
                a[j]=a[j]-min(a[i],a[j]);
            }
            else
            {
                a[i]=a[i]-min(a[i],a[j]);
                a[j]=a[j]-min(a[i],a[j]);
            }
            if(a[i]==0)
            {
                i++;
            }
            if(a[j]==0)
            {
                j--;
            }
            if(i==n/2&&a[i+1]==0&&a[i-1]==0
               ||j==n/2&&a[j+1]==0&&a[j-1]==0)
            {
                    break;
            }
        }
    }
    cout<<f;
    return 0;

}

