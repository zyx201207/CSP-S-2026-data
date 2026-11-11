#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    bool z=0;
    cin>>n;
    int c1[n+2];
    char c2[n+2];
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c1[i]>>c2[i];
    }
    if(n==2)
    {
        if(c2[1]==c2[2])
        {
            cout<<"0";
            return 0;
        }
        cout<<abs(c1[1]-c1[2]);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(c2[i]==c2[i+1])
        {
            z=1;
        }
        else{
            z=0
        }
    }
    if(z)
    {
        cout<<"0";
    }
    else{
        cout<<"1";
    }
}
