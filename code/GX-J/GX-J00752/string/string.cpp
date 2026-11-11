#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
long a;
char c;
string x,xx;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            xx=c+xx;
            x=x+c;
        }
    }
    for(int i=0;i<x.size()/2;i++)
        if(x[i]!=xx[i])
            sum++;
    cout<<sum;
    return 0;
}
