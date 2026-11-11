#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p,ans,cnt,sum;
char k,d[100000005];
int flag;
struct A{
    int a;
    char c;
}q[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i].a>>q[i].c;
        sum+=q[i].a;
        for(int j=1;j<=q[i].a;j++)d[++cnt]=q[i].c;
    }
    for(int i=1;i<=cnt/2;i++)
    {
        if(d[i]!=d[cnt-i+1]) ans++;
    }
    cout<<ans;
    return 0;

}
