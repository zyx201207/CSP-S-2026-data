#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6+10;
int c,t;
int x[maxn];
int read()
{
    int f = 1,k = 0;
    char c = getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9')
    {
        k = k*10+c-'0';
        c = getchar();
    }
    return f*k;
}
void work()
{
    int n = read(),d = read();
    for(int i = 1;i<=n;i++)
    {
        x[i] = read();
    }
    int dx = x[2] - x[1];
}
signed main()
{
    c = read();t = read();
    for(int i = 1;i<=t;i++)
    {
        work();
    }
    return 0;
}
/*
Oct31==Dec25?
*/