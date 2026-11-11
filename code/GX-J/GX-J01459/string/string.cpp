#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    cin>>n;
    string s[200005],b;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s[i];
        for(int j = 1;j<=a[i];j++)
            b+=s[i];
    }

    return 0;
}
