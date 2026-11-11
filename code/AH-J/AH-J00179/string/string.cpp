#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,L;
int a[200005];
string b;
char x;
long long ans;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>x;
        L+=a[i];
        for(int j=1;j<=a[i];j++)
            b+=x;
    }
    for(int i=0,j=L-1;i<=j;i++,j--)
        if(b[i]!=b[j]) ans++;
    cout<<ans;
    return 0;
}
