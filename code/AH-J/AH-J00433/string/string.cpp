#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string c,d;
    int a,b,e=0,num=0,y=0;
    cin>>a;
    if (a==1)
    {
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=a;i++)
    {
        cin>>b;
        cin>>c;
        e+=b;
        for (int j=1;j<=b;j++)
        {
            d+c;
        }

    }
    for (int i=0;i<e/2;i++)
    {
        if (d[i]==d[e-i-1])
        {


        }
        else{
            num++;
        }

    }
    cout<<num;
    return 0;
}
