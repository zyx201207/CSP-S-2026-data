#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    double n,n1,cnt=0;
    cin>>n;
    string s1,s="",s9="";
    for(long long i=0;i<n;i++)
    {
        cin>>n1>>s1;
        for(long long j=0;j<n1;j++) s+=s1;

    }
    s9=s;
    reverse(s9.begin(),s9.end());
    long long g=s.size();
    for(long long i=0;i<ceil(g/2);i++)
    {
        if(s[i]!=s9[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
