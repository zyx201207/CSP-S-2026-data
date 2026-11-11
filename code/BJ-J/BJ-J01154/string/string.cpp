#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
char c[N];
int a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(),cin.tie(),cout.tie();
    int n;
    cin>>n;
    string s;
    ll len=0,idx=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=idx;j<=idx+a[i];j++)
        {
            s[j]=c[i];
        }
        idx+=a[i];
    }
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]!=s[len-i+1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

