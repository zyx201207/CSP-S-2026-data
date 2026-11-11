#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int a=0;int b=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if (c=='-')
        {
            b=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    return 0;
}