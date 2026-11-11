#include<bits/stdc++.h>
const long long N=5e5+5,M=3e5+5;
long long cnt[M],n,m,a[N],ct[M],b[N],nd;
int main()
{
    std::freopen("card.in","r",stdin);
    std::freopen("card.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    std::cin >> n >> m;
    for(int i=1;i<=n;++i)
        std::cin >> a[i];
    for(int gm=1;gm<=n;++gm)
    {
        std::memset(ct,0,sizeof ct);
        nd=0;
        for(int i=gm;i<=n;++i)
        {
            b[++nd]=a[i];
            if(ct[b[nd]])
            {
                long long l=ct[b[nd]];
                nd--;
                for(;nd>l;--nd)
                    ct[b[nd]]=0;
            }
            else
                ct[b[nd]]=nd;
        }
        for(int i=1;i<=nd;++i)
            cnt[b[i]]++;
    }
    for(int i=1;i<=m;++i)
        std::cout << cnt[i] << ' ';
    return 0;
}
