#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,cnt;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)s+=b;
    }
    long long len=s.size();
    for(int i=0;i<=len/2;i++)
    {
        if(s[i]!=s[len-1-i])cnt++;
    }
    cout<<cnt;
    return 0;
}