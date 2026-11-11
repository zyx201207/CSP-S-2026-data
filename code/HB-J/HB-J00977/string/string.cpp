#include<bits/stdc++.h>
using namespace std;
long long check(string s)
{
    long long count=0;
    for(long long i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--)
    {
        if(s[i]!=s[j])
        count++;
    }
    return count;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    string huiwen;
    for(int i=1;i<=a;i++)
    {
        long long b;
        char c;
        cin>>b>>c;
        for(long long j=1;j<=b;j++)
        huiwen+=c;
    }
    cout<<check(huiwen);
    return 0;
}
