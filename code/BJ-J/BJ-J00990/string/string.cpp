#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;
int n,a[N];
char c[N];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        int x; char ch; cin >> x >> ch;
        for(int j=1;j<=x;j++) s+=ch;
    }
    int len=s.size();
    s=" "+s;
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]!=s[len+1-i]) ans++;
    }
    cout << ans/2;
    return 0;
}

