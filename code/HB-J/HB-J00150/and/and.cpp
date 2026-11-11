#include <bits/stdc++.h>
using namespace std;
using mpair=pair<int,int>;
const int N=2*1e5+100;
int d[N],cnt[N];
bool k[N][30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        int t=d[i],pos=1;
        while(t!=0)
        {
            k[i][pos]=t&1;
            if(t&1) cnt[i]++;
            t=t>>1;
        }
    }
    set <mpair> s;
    for(int i=20;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(k[j][i])
                s.insert(make_pair(cnt[j],j));
            if(s.size()>m) s.erase(s.begin());
        }
    }
    int ans=(1>>21)-1;
    for(auto a:s) ans=ans&(d[a.second]);
    cout<<ans<<'\n';
    return 0;
}