#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr int N = 500015;
int n;
ll nl[N],m,hl[N];

ll calc(int l,int r)
{
    return (r - l + 1) * nl[l] - (hl[r] - hl[l - 1]);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%lld",nl + i);
    sort(nl + 1,nl + n + 1,[](ll a,ll b) {return a > b;});
    for(int i = 1;i <= n;i++)
        hl[i] = hl[i - 1] + nl[i];
    int p = 1,ans = 0;
    for(int i = 1;i <= n;i++)
    {
        while(p < n && calc(i,p + 1) <= m) p++;
        ans = max(ans,p - i + 1);
    }
    printf("%d\n",ans);
    return 0;
}