#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>m)
                s=a[i];
        }
        cout<<s;
    }
    else if(m==2)
    {
        int s=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]&a[j]>s)
                    s=a[i]&a[j];
            }
        }
        cout<<s;
    }
    if(m==n)
    {
        for(int i=1;i<n;i++)
        {
            a[0]=a[i]&a[i+1];
        }
        cout<<a[0];
    }
    return 0;
}
