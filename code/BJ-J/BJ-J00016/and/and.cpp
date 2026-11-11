#include <bits/stdc++.h>
using namespace std;

long long a[2000005];
int main()
{
    fropen("and.in","r","stdin");
    fropen("and.out","w","stdout");
    long long n,m;
    cin >>n>>m;
    for (long long i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    if (m==2)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==3)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++) ans=max(ans,a[i]&a[j]&a[k]);
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==4)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++) ans=max(ans,a[i]&a[j]&a[k]&a[l]);
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==5)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++)
                    {
                        for (long long o=l+1;o<=n;o++) ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]);
                    }
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==6)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++)
                    {
                        for (long long o=l+1;o<=n;o++)
                        {
                            for (long long p=o+1;p<=n;p++) ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
                        }
                    }
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==7)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++)
                    {
                        for (long long o=l+1;o<=n;o++)
                        {
                            for (long long p=o+1;p<=n;p++)
                            {
                                for (long long q=p+1;q<=n;q++) ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
                            }
                        }
                    }
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==8)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++)
                    {
                        for (long long o=l+1;o<=n;o++)
                        {
                            for (long long p=o+1;p<=n;p++)
                            {
                                for (long long q=p+1;q<=n;q++)
                                {
                                    for (long long r=q+1;r<=n;r++) ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    if (m==9)
    {
        long long ans=0;
        for (long long i=1;i<=n;i++)
        {
            for (long long j=i+1;j<=n;j++)
            {
                for (long long k=j+1;k<=n;k++)
                {
                    for (long long l=k+1;l<=n;l++)
                    {
                        for (long long o=l+1;o<=n;o++)
                        {
                            for (long long p=o+1;p<=n;p++)
                            {
                                for (long long q=p+1;q<=n;q++)
                                {
                                    for (long long r=q+1;r<=n;r++)
                                    {
                                        for (long long t=r+1;t<=n;t++) ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[t]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout <<ans<<endl;
        return 0;
    }
    return 0;
}
