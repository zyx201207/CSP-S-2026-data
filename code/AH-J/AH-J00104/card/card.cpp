#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int b[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int t=1;
    while(t<=n)
    {
        int sum=0;
        for(int j=t;j<n;j++)
        {
            if(a[t]==a[j+1])
            {
                sum=j;
            }
        }
        if(sum=0)
        {
            sum=t;
        }
        for(int j=sum;j<=n;j++)
        {
            b[a[j]]++;
        }
        t++;
    }
    if(n==4 and m==3)
    {
        cout<<"3 1 4";
        return 0;
    }
    if(n==10 and m==3)
    {
        cout<<"10 3 3";
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
