#include <bits/stdc++.h>
using namespace std;
struct st
{
    long long k;
    char c;
} str[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0,cnt1=0;
    string s,s1;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> str[i].k >> str[i].c;
        for(int j=1;j<=str[i].k;j++)
        {
            s+=str[i].c;
        }
        cnt+=str[i].k;
    }
    for(int i=s.size()-1;i>=0;i--)
        {
            s1+=s[i];
        }
    if(s==s1)
    {
        cout << 0;
        return 0;
    }
    if(cnt==2)
    {
        cout << 1;
        return 0;
    }
    if(cnt%2==1)
    {
        for(int i=cnt/2+1;i<s.size();i++)
        {
            if(s[i]!=s[0])
            {
                cnt1++;
            }
        }
    }
    else if(cnt%2==0)
    {
        for(int i=cnt/2;i<s.size();i++)
        {
            if(s[i]!=s[0]&&s[i])
            {
                cnt1++;
            }
        }
    }
    cout << cnt1;
    return 0;
}

