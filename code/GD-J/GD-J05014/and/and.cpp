#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int max;
    cin>>n>>m;
    int a[n+5]={0};
    int maxn[m+5]={0};

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n+1,cmp);

    if (m==1)
    cout<<a[0];

    else if (m==n)
    {
        max=a[0];
        for(int i=0;i<n-1;i++)
        {
            max=max&a[i+1];
        }
        cout<<max;
    }

    else
    {
        for (int i=0;i<m;i++)
        {
            maxn[i]=a[i];
        }
        max=a[0];
        for(int i=0;i<m-1;i++)
        {
            max=max&a[i+1];
        }
        cout<<max;
    }
    
    return 0;
}
