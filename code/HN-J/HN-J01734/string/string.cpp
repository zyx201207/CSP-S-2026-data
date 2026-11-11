#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s[]={};
    string x;
    int n,a,s1=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        cin>>a;
        cin>>x;
        s1+=a;
        for(int j=0;j<a;j++)
        {
            s[s1+j]=x;
        }
    }
    cout<<s;

    return 0;
}
