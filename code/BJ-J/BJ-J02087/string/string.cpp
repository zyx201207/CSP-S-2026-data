#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200007];
char c[200007];
//map<char,vector<int>> mp;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int p=1;
    string s="";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int ans=0;
    int len=s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
