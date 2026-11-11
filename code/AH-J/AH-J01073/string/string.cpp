#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char ch[N];
long long ans;
signed main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>ch[i];
    int l=1,r=n,cnt;
    while(l<r)
    {
        cnt=min(a[l],a[r]);
        if(ch[l]!=ch[r])ans+=cnt;
        a[l]-=cnt,a[r]-=cnt;
        if(!a[l])l++;
        if(!a[r])r--;
    }
    cout<<ans;
    return 0;
}
