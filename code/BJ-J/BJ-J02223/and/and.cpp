#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and,out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int Max=-0x3f3f3f3f;
    for(int i=0;i<n;i++)
    {
        if(a[i]>Max)Max=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==Max)a[i]=-1;
    }
    Max=-0x3f3f3f;
    for(int i=0;i<n;i++)
    {
        if(a[i]>Max)Max=a[i];
    }
    cout<<Max;
    return 0;
}