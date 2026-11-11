#include <bits/stdc++.h>
using namespace std;
long long t;
string s,s2;
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> t;
    while(t--)
    {
        long long a;char s1;
        cin >> a >> s1;
        for(int i = 1;i <= a;i++)
        {
            s += s1;
        }
    }
    s2 = s;
    reverse(s.begin(),s.end());
    for(int i = 0;i < s.size()/2;i++)
    {

        if(s[i] != s2[i])
            sum++;
    }
    cout << sum;
}