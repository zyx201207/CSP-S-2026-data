#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b,n,k,p=0;
    string s,l;
    cin>>a;
    for(long long i=1;i<=a;i++)
    {
        cin>>b;
        cin>>l;
        for(long long j=b;j>0;j--)
        {
            s+=l;
        }
    }
    if(s.size()%2==0)
    {
        n=s.size()/2;
        k=1;
    }
    else
    {
        n=s.size()/2+1;
        k=2;
    }
    for(long long i=n;i<s.size();i++)
    {
        if(s[i]!=s[i-k])
        {
            s[i]=s[i-k];
            p++;
        }
        k+=2;
    }
    cout<<p;
    return 0;
}
