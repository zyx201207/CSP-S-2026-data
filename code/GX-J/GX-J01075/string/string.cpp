#include<bits/stdc++.h>
using namespace std;
long long n,a,m,x;
char b[200000001],c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=m+1;j<=m+a;j++)
        {
            b[j]=c;
        }
        m+=a;
    }
    for(int i=1;i<=n/2;i++)
    {
        if(b[i]!=b[m+1-i])
        {
            x++;
        }
    }
    cout<<x;
    return 0;
}
