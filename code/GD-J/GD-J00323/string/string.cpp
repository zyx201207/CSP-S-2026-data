#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
vector<pair<int,char>> L,R;
int num[maxn],n,ans;char ch[maxn];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;int sum = 0;
    for(int i = 1;i <= n;i++)cin >> num[i] >> ch[i],sum += num[i];
    int res = 0;
    for(int i = 1;i <= n;i++)
    {
        if(res + num[i] <= (sum + 1) / 2)L.push_back({num[i],ch[i]}),res += num[i];
        else{L.push_back({(sum + 1) / 2 - res,ch[i]});break;}
    }
    res = 0;
    for(int i = n;i >= 1;i--)
    {
        if(res + num[i] <= (sum + 1) / 2)R.push_back({num[i],ch[i]}),res += num[i];
        else{R.push_back({(sum + 1) / 2 - res,ch[i]});break;}
    }
    int tmpl = 0,tmpr = 0;
    while(tmpl < L.size() && tmpr < R.size())
    {
        pair<int,char> l = L[tmpl],r = R[tmpr];
        if(l.second == r.second)
        {
            if(l.first < r.first)R[tmpr].first -= l.first,tmpl++;
            else if(l.first > r.first)L[tmpl].first -= r.first,tmpr++;
            else tmpl++,tmpr++;
        }
        else
        {
            if(l.first < r.first)R[tmpr].first -= l.first,tmpl++;
            else if(l.first > r.first)L[tmpl].first -= r.first,tmpr++;
            else tmpl++,tmpr++;ans += min(l.first,r.first);
        }
    }
    cout << ans;
    return 0;
}
/*
我想要 我想要你知道
每一个脆弱的瞬间
都有我陪在你身旁
*/