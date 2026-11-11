#include <bits/stdc++.h>
using namespace std;
long long n,s[10000005],m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    if(s[n]==s[n-1])
    {
        cout <<s[n];
    }
    else if(s[n]>s[n-1])
    {
        cout <<s[n] and s[n-1];
    }

    return 0;
}
