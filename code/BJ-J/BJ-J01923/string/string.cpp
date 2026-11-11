#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct ch
{
    int a;
    char c;
}s[maxn];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >>n;
    long long len=0;
    for(int i=1; i<=n; ++i)
    {
        cin >>s[i].a;
        cin >>s[i].c;
        len+=1LL*s[i].a;
    }
    long long cnt=0;
    int k1=1, k2=n;
    int i=1, j=s[n].a;
    long long t=len/2;
    while(t--)
    {
        if(i>s[k1].a)
        {
            k1++;
            i=1;
        }
        if(j<1)
        {
            k2--;
            j=s[k2].a;
        }
        if(s[k1].c!=s[k2].c)
        {
            cnt++;
        }
        i++;
        j--;
    }
    cout <<cnt;
    return 0;
}
