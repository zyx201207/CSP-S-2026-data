#include<bits/stdc++.h>
const long long N=2e5+10;
long long n,m,a[N],ans,lst;
long long cnt[32][32];
std::vector<long long> ct[32][32];
int main()
{
    std::freopen("and.in","r",stdin);
    std::freopen("and.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    std::cin >> n >> m;
    lst=31;
    for(int i=1;i<=n;++i)
        std::cin >> a[i];
    std::sort(a+1,a+1+n,std::greater<long long>());
    for(int i=1;i<=n;++i)
        for(int j=1;j<=30;++j)
            if((bool)(a[i]&(1<<(j-1))))
                cnt[31][j]++,ct[31][j].push_back(i);
    for(int i=30;i>=1;i--)
    {
        if(cnt[lst][i]>=m)
        {
            ans+=1<<(i-1);
            bool ck=0;
            for(int j=i-1;j>=1;--j)
            {
                for(auto v:ct[lst][i])
                {
                    if((bool)(a[v]&(1<<(j-1))))
                    {
                        cnt[i][j]++;
                        ct[i][j].push_back(v);
                        if(cnt[i][j]>=m)
                        {
                            ck=1;
                            lst=i;
                            i=j+1;
                            break;
                        }
                    }
                }
                if(ck)break;
            }
            if(!ck)break;
        }
    }
    std::cout << ans;
    return 0;
}
