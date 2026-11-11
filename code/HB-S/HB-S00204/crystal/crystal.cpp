#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b)
{
    return a<b;
}

long long a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt=0;
    cin >> n >> m;
    for (long long i = 0;i < n;i++)
    {
        cin >> a[i];
        if (a[i]==i+1)
        {
            cnt++;
        }
    }
    if (cnt==n)
    {
        int t[500005]={};
        int i = 0,j=2;
        while(i<m)
        {
            for (int k=1;k<=j;k++)
            {
                t[i]=j;
                i++;
            }
            j++;
        }
        cout << t[m-1];
        return 0;
    }
    sort(a,a+n,cmp);
    long long x,maxx=-33554432,maxs=0;
    while(true)
    {
        for (long long i = 1;i < n;i++)
        {
            if (a[i]!=a[0]&&a[i]>maxx)
            {
                x=i;
                maxx=a[i];
                break;
            }
        }
        if ((a[x]-a[0])*x<=m)
        {
            m-=(a[x]-a[0])*x;
            for (long long i = 0;i < x;i++)
            {
                a[i]=a[x];
            }
        }
        else
        {
            if(m==0)
            {
                for (int i = 1;i < n;i++)
                {
                    if (a[i]<=maxx)
                    {
                        maxs++;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            }
            long long k[500005]={},les=a[x-1],p=0,q=0,maxk=-1;
            for (long long i = 0;i < m%x;i++)
            {
                a[i]++;
                for (long long j = 0;j < n;j++)
                {
                    if (a[j]==maxx)
                    {
                        p++;
                    }
                    if (a[j]>maxx)
                    {
                        break;
                    }
                }
                for (long long j = 0;j < n;j++)
                {
                    if (a[j]==les)
                    {
                        q++;
                    }
                    if (a[j]>les)
                    {
                        break;
                    }
                }
                k[i]=max(q,p);
            }
            for (long long i = 0;i <= m%x;i++)
            {
                if (k[i]>maxk)
                {
                    maxk=k[i];
                }
            }
            maxs=max(maxs,maxk);
            break;
        }
    }
    cout << maxs;

    return 0;
}
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
