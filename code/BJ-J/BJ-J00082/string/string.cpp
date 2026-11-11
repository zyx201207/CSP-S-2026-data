#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    long long p;
    if(s.size()%2==0)
    {
        p=s.size()/2-1;
    }
    else{
        p=(s.size()-1)/2-1;
    }
    for(long long i=0;i<=p;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
