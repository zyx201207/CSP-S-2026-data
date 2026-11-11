#include <bits/stdc++.h>
using namespace std;

long long a[20005];
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n,m;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    if (m==1)
    {
        sort(a,a+n,cmp);
        cout << a[0];
        return 0;
    }
    else if (m==2)
    {
        int sum=0,maxs=0;
        for (int i = 0;i < n-1;i++)
        {
            for (int j = i+1;j < n;j++)
            {
                sum = a[i]&a[j];
                if (sum>maxs)
                {
                    maxs=sum;
                }
            }
        }
        cout << maxs;
        return 0;
    }
    else{
        int sum=0,maxs=0;
        for (int i = 0;i < n-m;i++)
        {
            sum = a[i];
            for (int j = i+1;j < i+m-1;j++)
            {
                sum=sum&a[j];
            }
            if (sum>maxs)
            {
                maxs=sum;
            }
        }
        cout << maxs;
        return 0;
    }

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

