#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt=0;
int a[200010];
char c[200010];
string s=" ";
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for (int i=1;i<=n/2;i++)
    {
        if(c[i]!=c[n+1-i])
        {
            cnt+=max(a[i],a[n+1-i]);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
