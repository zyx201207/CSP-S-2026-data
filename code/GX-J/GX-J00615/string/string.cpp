#include<bits/stdc++.h>
using namespace std;
long long n,a1,x=0,ans=0,h=0;
int main()
{
    char c1;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1>>c1;
        for(int j=1;j<=a1;j++)
        {
            s+=c1;
        }
    }
    x=s.size();
    h=s.size()/2;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[x])
        {
            ans++;
        }
        x--;
        if(x==h)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
