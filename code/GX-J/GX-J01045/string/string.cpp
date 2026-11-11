#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int i,n,m=0,a[200001];

    cin>>n;
    fot(i=1;i<=n;i++)
    {
       cin>>a[i]>>s[i];
    }
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    for(i=1;i<=n-1;i++)
    {
        if(s[i]!=s[i+1]) braek;
        else m++;
    }
    if(m==n-1)
    {
        cout<<"0"
        return 0;
    }
    if(n==2&&s[1!=s[2])
    {
        cout<<"1"
        return 0;
    }
    return 0;
}
