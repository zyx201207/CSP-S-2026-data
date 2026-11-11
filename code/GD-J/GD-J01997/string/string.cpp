#include <bits/stdc++.h>
using namespace std;
int a[200005],n,ans,maxc,maxa,maxb;
char c[200005];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >>c[i];
        maxc=max(maxc,a[i]);
    }
    if (maxc<=50)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=a[i];j++)
            s+=c[i];
        }
        for (int i=0;i<(s.size()-1)/2;i++)
            ans+=(s[i]!=s[s.size()-i-1]);
        cout <<ans;
    }
    return 0;
}
