#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    
    int a[n+5];
    char c[n+5];

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }

    string s="";

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<a[i];j++)
        {
            s+=c[i];
        }
    }

    int different=0;

    for (int i=0;i<(n/2);i++)
    {
        if (s[i]!=s[n-i-1])
        different++;
    }

    cout<<different;
    return 0;
}
