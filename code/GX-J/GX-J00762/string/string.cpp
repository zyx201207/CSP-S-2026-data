#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for (int j=1;j<=a;j++)
            s+=c;
    }
    int len=s.size();
    string s_1,s_2;
    if (len%2)
    {
        for (int i=0;i<len/2;i++)
            s_1+=s[i];
        for (int i=len-1;i>len/2;i--)
            s_2+=s[i];
    }
    else
    {
        for (int i=0;i<len/2;i++)
            s_1+=s[i];
        for (int i=len-1;i>=len/2;i--)
            s_2+=s[i];
    }
    int cnt=0;
    for (int i=0;i<len/2;i++)
    {
        if (s_1[i]!=s_2[i])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
