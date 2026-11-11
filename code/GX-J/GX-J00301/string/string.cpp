#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0,a=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long m;
        char x;
        cin>>m>>x;
        for(int j=1;j<=m;j++)
        {
            s=s+x;
        }
    }
    a=s.size();
    for(int i=0;i<a/2;i++)
    {
        if(s[i]!=s[a-1-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
