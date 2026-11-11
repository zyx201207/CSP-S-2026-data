#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=19;i>=0;i--)
    {
        int tot=ans+(1<<i),fl=0;
        for(int j=1;j<=n;j++) if((a[j]&tot)==tot) fl++;
        if(fl>=m) ans=tot;
    }
    cout<<ans;
    return 0;
}
//心静自然凉>信竞自然凉>信竞自然娘>信竞都是猫娘喵
