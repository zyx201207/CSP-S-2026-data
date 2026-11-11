#include<bits/stdc++.h>
using namespace std;
int a[5050];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,flag=1,k,i,z=1;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        long long cost=0;
        for(int j=i;j<=n;j++)
        {
            cost=cost+(j-i)*(a[j]-a[j-i]);
            if(cost>m)
            {
                break;
            }
            else
            {
                z=max(z,j-i+1);
            }
        }
    }
    cout<<z;
    return 0;
}
