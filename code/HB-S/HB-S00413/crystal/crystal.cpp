#include<bits/stdc++.h>
using namespace std;

int a[500050];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            while(a[i]<a[j])
            {
                if(a[i]<a[j])
                {
                    int t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
    }
    long long mid;
    if(n%2==0)
    {
        mid=n/2;
    }
    else
    {
        mid=(n+1)/2;
    }
    long long s=m+1;
    while(s<=m)
    {
        s=0;
        for(int i=mid+1;i>=0;i--)
        {
            s+=a[i];
        }
        mid--;
    }
    while(1)
    {
        if(a[mid-2]==a[mid-1])
        {
            mid++;
        }
        else
        {
            break;
        }
    }
    cout<<mid;
    return 0;
}
