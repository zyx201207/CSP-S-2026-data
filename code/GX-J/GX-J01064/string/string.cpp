#include <bits/stdc++.h>

using namespace std;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w",stdout);
    int o,cnt=0;
    cin>>o;
    for(int i=0;i<o;i++)
    {
        int sz;
        char s1;
        cin>>sz>>s1;
        for(int j=0;j<sz;j++)
            s+=s1;
    }
    string s1="",s2="";
    int n=s.size();
    for(int i=0;i<n/2;i++)
        s1+=s[i];
    for(int i=n-1;i>n/2;i--)
        s2+=s[i];
    for(int i=0;i<n/2;i++)
    {
        if(s1[i]!=s2[i])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
