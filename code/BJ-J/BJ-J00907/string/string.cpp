#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
long long a[maxn];
char c[maxn];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int ans=0,tot=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            s[++tot]+=c[i];
        }
    }
    for(int i=1;i<=tot/2;i++)
    {
        if(s[i]!=s[tot+1-i]) ans++;
    }
    cout<<ans;
    cout<<endl;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/