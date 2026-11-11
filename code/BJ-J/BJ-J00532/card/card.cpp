#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n=0,m=0;
    cin>>n>>m;
    vector<long long> pai(n+2,0);
    deque<long long> now;
    vector<long long> biao(n+2,-1);
    vector<long long> cnt(n+2,0);
    for(long long i=1;i<=n;i++)
    {
        cin>>pai[i];
    }
    for(long long i=n;i>=1;i--)
    {
        long long c=pai[i];
        if(biao[c]==-1)
        {
            now.push_front(c);
            cnt[c]=cnt[c]+i;
            biao[c]=1;
        }
        else
        {
            while(1)
            {
                long long zhong_jie=now.front();
                now.pop_front();
                if(zhong_jie==c)
                {
                    break;
                }
                else
                {
                    cnt[zhong_jie]=cnt[zhong_jie]-i;
                    biao[zhong_jie]=-1;
                }
            }
            now.push_front(c);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
