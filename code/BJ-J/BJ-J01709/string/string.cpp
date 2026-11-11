#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a=0,b=0,i,j,n,m=0;
    char c,d[1000000];
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a>>c;
        //cout<<a<<" "<<c<<endl;
        for (j=0;j<a;j++)
        {
            d[j+m]=c;

        }
        m+=a;
    }
    /*
    for (i=0;i<m;i++)
    cout<<d[i];*/
    //d[m]={'a','a','a','a','a'};
    for (i=0;i<m/2;i++)
    {
        if (d[i]!=d[m-1-i])
        {
            b++;
            //cout<<i<<endl;
        }
    }
    cout<<b<<endl;
    return 0;
}
