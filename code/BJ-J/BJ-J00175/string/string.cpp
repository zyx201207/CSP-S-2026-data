#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a;
char c;
string t;
int ans;

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            t.push_back(c);
    }
    for(int i=0;i<(t.size()/2);i++)
    {
        if(t[i]!=t[t.size()-1-i])
            ans++;
    }
    cout<<ans;
    return 0;
}
