#include <bits/stdc++.h>
using namespace std;
char a;
long long cnt=0;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,x;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> x >> a;
        for (int j=0;j<x;j++)
        {
            s+=a;
        }
    }
    for (int i=0;i<s.size()/2;i++)
    {
        if (s[i]!=s[s.size()-i-1])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
