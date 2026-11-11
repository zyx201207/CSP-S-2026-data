#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long t = n;
    vector<long long> v(n);
    for(long long i = 0;i < n;i++) cin>>v[i];
    vector<long long> ans(m + 5,0);
    while(t--)
    {
        deque<long long> cards;
        for(long long i = n - t - 1;i < n;i++)
        {
            deque<long long> use = cards;
            bool flag = false;
            while(!use.empty())
            {
                if(use.back() == v[i])
                {
                    use.pop_back();
                    flag = true;
                    break;
                }
                use.pop_back();
            }
            if(flag) cards = use;
            cards.push_back(v[i]);
        }
        for(long long i : cards) ans[i]++;
    }
    for(long long i = 1;i <= m;i++) cout<<ans[i]<<" ";
    return 0;
}
