#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e8+10;
int n, ans=0;
char z[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        char s;
        cin>>x>>s;
        while(x--)
        {
            z[++num]=s;
        }
    }
    for(int i=1, j=num;i<=j;i++, j--)
    {
        if(z[i]!=z[j])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
