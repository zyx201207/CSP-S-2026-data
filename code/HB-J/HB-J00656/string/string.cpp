#include <bits/stdc++.h>
using namespace std;
string s;
long long len, cnt,n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        char c;
        cin>>c;
        for(int j=0;j<t;j++)s.push_back(c);
        len +=t;
    }
    for(int i=len-len/2;i<len;i++)
    {
        if(s[i]!=s[len-i-1])cnt++;
    }
    cout<<cnt;
    return 0;
}
