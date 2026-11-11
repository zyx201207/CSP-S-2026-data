#include<bits/stdc++.h>

using namespace std;

unsigned long long  n,cc,temp;
string s = "",a;

bool Pan(string s)
{
    for(int i = 0;i<s.size()/2;i++)
    {
        if(s[i] != s[s.size()-i-1])
            return false;
    }
    return true;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>temp;
        cin>>a;
        for(int i = 0;i<temp;i++)
        {
            s+=a;
        }
    }
    unsigned long long  t = 0;
    while(1)
    {
        if(Pan(s) == true)
        {
            break;
        }
        if(s[t] != s[s.size()-t-1])
        {
            s[s.size()-t-1] = s[t];
            cc++;
        }
        t++;
    }
    cout<<cc;
    return 0;
}

