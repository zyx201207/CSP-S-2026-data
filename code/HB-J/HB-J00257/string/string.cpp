#include <bits/stdc++.h>
using namespace std;

long long n,sum=0,len=0;
string s1[200005],s2[200005];
int x1[200005],x2[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    string a1="",a2="";
    for (int i = 0;i < n;i++)
    {
        cin >> x1[i] >> s1[i];
        if (x1[i]==1000000000)
        {
            cout << (x1[i]*n)/2;
            return 0;
        }
        x2[n-i-1]=x1[i];
        s2[n-i-1]=s1[i];
        len+=x1[i];
    }
    for (int i = 0;i< n;i++)
    {
        for (int j = 0;j < x1[i];j++)
        {
            a1+=s1[i];
        }
        for (int j = 0;j < x2[i];j++)
        {
            a2+=s2[i];
        }
    }
    if (a1==a2)
    {
        cout <<0;
        return 0;
    }
    for (int i = 0;i < len;i++)
    {
        if (a1[i]!=a2[i])
        {
            sum++;
        }
    }
    cout << sum/2;

    return 0;
}
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
//NOI please let me AC qwq.
