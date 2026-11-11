#include<bits/stdc++.h>
using namespace std;
long long a[222222];
char c[222222];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++)
            cin>>a[i]>>c[i];
    string s="";
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=a[i];j++)
            s+=c[i];
    long long l;
    l=s.size();
    string s1="",s2="";
    for(long long i=0;i<l/2;i++)
        s1+=s[i];
    if(l%2==1)
        for(long long i=l-1;i>l/2;i--)
            s2+=s[i];
    else
        for(long long i=l-1;i>=l/2;i--)
            s2+=s[i];
    long long ss=0;
    for(long long i=0;i<=l/2;i++)
        if(s1[i]!=s2[i])
            ss++;
    cout<<ss<<endl;
    return 0;
}
