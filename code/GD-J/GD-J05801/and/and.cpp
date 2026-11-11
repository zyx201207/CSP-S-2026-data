#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,max=0,b=0;
    cin>>n>>m;
    long long a[n+5];c
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=m;i<n;i++)
    {
        cin>>a[i];


    }
    for(int i=0;i<n;i++)
    {
        b=a[i];
        for(int j=1;j<i;j++)
        {
            b=b&a[j];
        }
        if(b>max)
        {
            max=b;
        }
    }
    cout<<b;
    return 0;
}
