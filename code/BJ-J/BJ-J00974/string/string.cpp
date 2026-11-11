#include<bits/stdc++.h>
using namespace std;

#define int long long
#define dnl "\n"

const int MAXN=2e5+5;

int n;
int a[MAXN];

string s="";

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    s="$"+s;

    cin>>n;

    int len=0;

    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>a[i];
        len+=a[i];
        cin>>ch;
        for(int j=1;j<=a[i];j++)
        {
            s+=ch;
        }
    }

    // cout<<s<<dnl;
    // cout<<s[5]<<dnl;
    // cout<<len<<dnl;

    int ans=0;

    for(int i=1;i<=len/2;i++)
    {
        if(s[i]!=s[len-i+1])
        {
            ans++;
        }
    }

    cout<<ans<<dnl;

    return 0;
}
