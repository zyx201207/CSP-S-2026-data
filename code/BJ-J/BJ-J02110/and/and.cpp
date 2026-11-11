#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,d,maxx=-10000;
    int b[1000000],c[1000000];
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>d;
    for(int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for(int j=0;j<a;j++)
    {
        for(int k=j;k<a;k++)
        {
            c[j]=b[j] && b[k];
            if(c[j]>maxx)
            {
                maxx=c[j];
            }
        }
    }
    cout<<maxx;
    return 0;
}
