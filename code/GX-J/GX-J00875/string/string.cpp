#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    string d[100000005],e[100000005];
    int n=0,a=0,c=0,f=0,b[100000005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b[i]>>d[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i];j++)
        {
            f++;
            e[f]=d[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(e[i]!=e[f-i-1])
        {
            c++;
        }
        else
        {
            a++;
        }
    }
    cout<<c;
    return 0;
}
