#include <bits/stdc++.h>
#define ll unsigned long long
#define int unsigned long long
using namespace std;
const int N = 2e5+5;
ll a[N];char c[N];
ll a1[N];char c1[N];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout << "done1\n";
    int n, nn = 0;
    cin >> n;
    bool is50 = 1;
    for(int i = 1; i <= n; i++)
        {
            cin >> a[i] >> c[i];
            if(a[i] > 50) is50 = 0;
            if(c[i] == c[i-1])
            {
                a1[nn] += a[i];
            }
            else
            {
                a1[++nn] = a[i];
                c1[nn] = c[i];
                // cout << c[i] << " ";
            }
        }
    if(n <= 2000 && is50)
    {
        string str = "";
        int len = 0;
        int T=n;
        for(int i = 1; i <= nn; i++)
        {
            str.resize(len+a1[i], c1[i]);
            len += a1[i];
        }
        int ans = 0;
        for(int i = 0; i*2 < len; i++)
        {
            if(str[i] != str[len-i-1]) ans++;
        }
        cout << ans << '\n';
        return 0;
    }
    else
    {
        
        // for(int i = 1; i <= nn; i++)
        // {
        //     cout << a1[i] << " " << c1[i] << '\n';
        // }
        // cout << "done1\n";
        deque<ll> la, ra;
        deque<char> lc, rc;
        for(int i = 1; i <= nn; i++)
        {
            int j = nn-i+1;
            if(i == j)
            {
                la.push_back(a1[i]);lc.push_back(c1[i]);break;
            }
            if(i >= j) break;
            la.push_back(a1[i]);lc.push_back(c1[i]);
            ra.push_back(a1[j]);rc.push_back(c1[j]);
        }


        // cout << "la:";
        // for(auto i : la)
        // {
        //     cout << i << " ";
        // }
        // cout << "\nlc:";
        // for(auto i : lc)
        // {
        //     cout << i << " ";
        // }
        // cout << "\nra:";
        // for(auto i : ra)
        // {
        //     cout << i << " ";
        // }
        // cout << "\nrc:";
        // for(auto i : rc)
        // {
        //     cout << i << " ";
        // }

        ll ans = 0;
        while(1)
        {
            if(la.empty() && ra.empty())
            {
                cout << ans;
                return 0;
            }
            if(la.empty())
            {
                if(ra.size() == 1) break;
                else if(ra.size() > 1)
                {
                    la.push_back(ra.back());
                    lc.push_back(rc.back());
                    ra.pop_back();
                    rc.pop_back();
                }
            }
            if(ra.empty())
            {
                if(la.size() == 1) break;
                else if(ra.size() > 1)
                {
                    ra.push_back(la.back());
                    rc.push_back(lc.back());
                    la.pop_back();
                    lc.pop_back();
                }
            }
            if(lc.front() == rc.front())
            {
                if(la.front() == ra.front())
                {
                    la.pop_front();
                    ra.pop_front();
                    lc.pop_front();
                    rc.pop_front();
                }
                else if(la.front() > ra.front())
                {
                    la.front()-=ra.front();
                    ra.pop_front();
                    rc.pop_front();
                }
                else if(la.front() < ra.front())
                {
                    ra.front()-=la.front();
                    la.pop_front();lc.pop_front();
                }
            }
            else
            {
                if(la.front() == ra.front())
                {
                    ans += la.front();
                    la.pop_front();
                    ra.pop_front();
                    lc.pop_front();
                    rc.pop_front();
                }
                else if(la.front() > ra.front())
                {
                    ans += ra.front();
                    la.front()-=ra.front();
                    ra.pop_front();
                    rc.pop_front();
                }
                else if(la.front() < ra.front())
                {
                    ans += la.front();
                    ra.front()-=la.front();
                    la.pop_front();lc.pop_front();
                }
            }
        }
        int k = 1;
        cout << ans;
    }
    return 0;
}
