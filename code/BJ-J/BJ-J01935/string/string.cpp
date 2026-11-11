#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long l,n,i=1;
    string a,a1,a2;
    char s;
    cin>>l;
    for(i=1;i<=l;i++)
    {
        cin>>n>>s;
        for(int j=1;j<=n;j++)
        {
            a+=s;
        }
    }
    a1=a.substr(0,a.size()/2);
    if(a.size()%2==1)
    {
        a2=a.substr(a1.size()+1);
    }
    else
    {
        a2=a.substr(a1.size()+2);
    }
    long long cnt=0;
    for(i=0;i<a1.size();i++)
    {
        if(a1[i]!=a2[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}