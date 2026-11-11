#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string c;
string h;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;

cin>>n;
    int a;
    string b;

    int g=0;
    int d=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;

        for(long long i=1; i<=a; i++)
        {
            c+=b;
        }
    }

    for(long long i=0; i<c.size()/2; i++)
    {
        if(c[i]!=c[n-i])
        {
            g++;
        }
    }
    cout<<g;


}
