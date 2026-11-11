#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[214514];
char c[214514];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s=" ";
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;char c;
        cin>>x>>c;
        sum+=x;
        if(sum>=10000000) cout<<0,exit(0);
        if(c<'a'||c>'z') return 0;
        while(x--) s+=c;
    }
    int ans=0,L=s.size();
    for(int i=1;i<=L/2;i++)
        ans+=(s[i]!=s[L-i]);
    cout<<ans;
    return 0;
}
