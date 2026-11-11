#include <bits/stdc++.h>
using namespace std;
char s[100000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    char a;
    long long x;
    long long y = 1;
    long long q = 0;
    long long z = 0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>x>>a;
        z += x;
        for(int u=y;u<=y + x - 1;u++)
        {
            s[u] = a;
        }
        y += x;
    }
    for(long long i=1;i<=z / 2;i++)
    {
        if(s[i] != s[z - i + 1])
        {
            q++;
        }
    }
    cout<<q;
    return 0;
}
