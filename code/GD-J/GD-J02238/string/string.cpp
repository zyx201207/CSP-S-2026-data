#include <bits/stdc++.h>
using namespace std;
string s,chhh;
long long ans;
int main()
{
long long n,num;
cin >> n;
for(int i = 1;i<=n;i++)
{
    cin >> num >> chhh;
    for(int j = 1;j<=num;j++)
    {
        s += chhh;
    }
}
string ss = s;
reverse(s.begin(),s.end());
for(int h = 1;h<=(int)ss.size();h++)
{
    if(ss[h] != s[h])
    {
        ans++;
    }
}
cout << ans;
    return 0;
}
