#include<bits/stdc++.h>
using namespace std;

string s;
long long n,cnt=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for (int j=0;j<a;j++)
        {
            s+=c;
        }
    }
    long long len=s.size();
    for (int i=0;i<len/2;i++)
    {
        if (s[i]!=s[len-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}

