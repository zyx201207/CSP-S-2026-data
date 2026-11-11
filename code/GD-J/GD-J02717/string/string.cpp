#include<bits/stdc++.h>
using namespace std;
int a[10000000];
string c[10000000];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=0;i<=n;i++)
    {
       for(int j=0;j<=a[i];j++)
       {
           s=s+c[i];
       }

    }
    cout<<0;
    return 0;
}
