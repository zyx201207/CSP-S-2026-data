#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                int s=a[i];
                a[i]=a[j];
                a[j]=s;
            }
        }

    }
    cout<<a[m-1];
    return 0;
}
