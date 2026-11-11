#include<bits/stdc++.h>
using namespace std;
long long n,c[90000001],d[90000001],a=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        cin>>d[i];
        s+=c[i]*d[i];
    }
    if(s.size()%2==0)
    {
        a=0;
    }
    else
    {
        a=1;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            a++;
        }
    }
    cout<<a;
    return 0;
}
