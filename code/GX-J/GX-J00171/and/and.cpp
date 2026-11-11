#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n,m,s,o=100;
    cin>>n>>m;
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(o>0)
    {
        for(int i=0;i<n;i++)
    {
       if(a[i]>a[i+1])
        a[i+1]=s;
       a[i+1]=a[i];
       a[i]=s;
    }
    }

    cout<<a[ceil(n/2)];
    return 0;
}
