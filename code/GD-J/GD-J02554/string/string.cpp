#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        char q;
        cin >> q;
        for (int i=1;i<=a;i++) s+=q;
    }
    int ans=0;
    string sx;
    for (int i=s.length()-1;i>=0;i--)
    {
        sx+=s[i];
    }
    for (int i=0;i<s.length();i++)
    {
        if (s[i]!=sx[i]) ans++;
    }
    cout << ans/2;
    return 0;
}
