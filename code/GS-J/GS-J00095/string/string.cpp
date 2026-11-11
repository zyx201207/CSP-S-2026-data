#include<bits/stdc++.h>
using namespace std;
long long n;

string s="";

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        long long x;
        char y;
        cin>>x>>y;
        for(long long i=0;i<x;i++) s+=y;
    }
    long long cc=0;
    long long ppp=s.size()-1;
    for(long long i=0,j=ppp;i<=ppp/2,j>=ppp/2;i++,j--)
    {
        if(s[i]!=s[j]) cc++;
    }
    cout<<cc;


    return 0;
}
