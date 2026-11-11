#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,nmax=0,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    if(m==1)
    for(long long i=1;i<=n;i++)
    {
        if(a[i]>nmax)
        nmax=a[i];
    }
    if(m==2)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    {
        if((a[i] & a[j])>nmax)
        nmax=(a[i] & a[j]);
    }
    if(m==3)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    {
        if((a[i] & a[j] & a[k])>nmax)
        nmax=(a[i] & a[j] & a[k]);
    }
    if(m==4)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    for(long long l=k+1;l<=n;l++)
    {
        if((a[i] & a[j] & a[k] & a[l])>nmax)
        nmax=(a[i] & a[j] & a[k] & a[l]);
    }
    if(m==5)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    for(long long l=k+1;l<=n;l++)
    for(long long o=l+1;o<=n;o++)
    {
        if((a[i] & a[j] & a[k] & a[l] &a[o])>nmax)
        nmax=(a[i] & a[j] & a[k] & a[l] & a[o]);
    }
    if(m==7)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    for(long long l=k+1;l<=n;l++)
    for(long long o=l+1;o<=n;o++)
    for(long long p=o+1;p<=n;p++)
    for(long long q=p+1;q<=n;q++)
    {
        if((a[i] & a[j] & a[k] & a[l] &a[o] &a[p]& a[q])>nmax)
        nmax=(a[i] & a[j] & a[k] & a[l] & a[o] &a[p]&a[q]);
    }
    if(m==10)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    for(long long l=k+1;l<=n;l++)
    for(long long o=l+1;o<=n;o++)
    for(long long p=o+1;p<=n;p++)
    for(long long q=p+1;q<=n;q++)
    for(long long r=q+1;r<=n;r++)
    for(long long s=r+1;s<=n;s++)
    for(long long t=s+1;t<=n;t++)
    {
        if((a[i] & a[j] & a[k] & a[l] &a[o] &a[p]& a[q]&a[r]&a[s]&a[t])>nmax)
        nmax=(a[i] & a[j] & a[k] & a[l] & a[o] &a[p]&a[q]&a[r]&a[s]&a[t]);
    }
    if(m==11)
    for(long long i=1;i<=n;i++)
    for(long long j=i+1;j<=n;j++)
    for(long long k=j+1;k<=n;k++)
    for(long long l=k+1;l<=n;l++)
    for(long long o=l+1;o<=n;o++)
    for(long long p=o+1;p<=n;p++)
    for(long long q=p+1;q<=n;q++)
    for(long long r=q+1;r<=n;r++)
    for(long long s=r+1;s<=n;s++)
    for(long long t=s+1;t<=n;t++)
    for(long long u=t+1;u<=n;u++)
    {
        if((a[i] & a[j] & a[k] & a[l] &a[o] &a[p]& a[q]&a[r]&a[s]&a[t]&a[u])>nmax)
        nmax=(a[i] & a[j] & a[k] & a[l] & a[o] &a[p]&a[q]&a[r]&a[s]&a[t]&a[u]);
    }
    cout<<nmax;
}
