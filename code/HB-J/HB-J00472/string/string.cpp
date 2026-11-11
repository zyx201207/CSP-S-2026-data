#include <bits/stdc++.h>
using namespace std;
int a[200005],m,n,cnt;
string c,s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for (int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    for(int i=0;i<s.length()/2;i++)
    {
        if (s[i]!=s[s.length()-i-1])
        {
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
