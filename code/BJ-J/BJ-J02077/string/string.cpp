#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[100005]={};
    char b[100005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(n<=1)
    {
        cout<<0;
        return 0;
    }
    if(n<=2&&b[1]==b[2])
    {
        cout<<0;
        return 0;
    }
    if(n<=2&&b[1]!=b[2])
    {
        if(a[1]>a[2])
        {
            cout<<a[2];
        }
        else cout<<a[1];
    }
}
