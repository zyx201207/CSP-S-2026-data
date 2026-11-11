#include <bits/stdc++.h>
using namespace std;
struct s
{
    long long x;
    char y;
}s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    string k;
    long long a=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].x>>s[i].y;
        a+=s[i].x;
        for(int j=1;j<=s[i].x;j++)
        {
            k+=s[i].y;
        }
    }
    for(int i=0;i<k.size();i++)
    {
        if(k[i]!=k[a-1-i])
        {
            cnt++;
        }
    }
    cout <<cnt/2;
    return 0;
    }
