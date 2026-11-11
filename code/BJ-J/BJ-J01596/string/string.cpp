#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }
    int ans=0;
    for(int i=0;i<s.size()>>1;i++)
    {
        if(s[i]!=s[s.size()-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
