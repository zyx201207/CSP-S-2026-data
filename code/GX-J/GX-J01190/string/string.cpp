
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        for(int j=1;j<=a;i++)
        {
            char b;
            cin>>b;
            s+=b;
        }
    }
    string t;
    int sum=0;
    for(int i=s.size();i>=0;i++)
    {
        t+=s[i];
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=t[i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

