#include <bits/stdc++.h>
using namespace std;
string s;
string s1;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a;
    char c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }

    }
    long long len=s.size();
    for(int i=0;i<len;i++)
    {
        s1+=s[len-i-1];
    }
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=s1[i])
        {
            cnt++;
        }
    }
    if(cnt<=len/2)  cout<<cnt;
    else   cout<<cnt-len/2;
    return 0;
}
