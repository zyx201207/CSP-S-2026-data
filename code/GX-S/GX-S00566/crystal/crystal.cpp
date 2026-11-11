#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    long long a[100005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int mi=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<a[i])
            {
                mi=a[j];
                a[j]=a[i];
                a[i]=mi;
            }
        }
    }

    int f=10000005,h;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]-a[i]<=f)
        {
            f=a[i+1]-a[i];
            h=i+1;
        }
    }

    int num=1;
    while(m>0)
    {
        for(int i=1;i<h;i++)
        {
            if(a[h-i] != a[h])
            {
                a[h-i]++;
                m--;
            }
            else
            {
                num++;
                continue;
            }
        }
    }
    cout<<num;
    return 0;
}
