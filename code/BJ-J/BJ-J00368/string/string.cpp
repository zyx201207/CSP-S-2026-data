#include<bits/stdc++.h>
#define int long long
using namespace std;

deque<string> dq;
long long pingfang[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 1000000000, 1000000000};
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        string a, b;
        cin >> a >> b;
        a += b;
        dq.push_back(a);
    }
    long long ans = 0;
    while(1)
    {
        if(dq.empty() || dq.size() == 1) break;
        string shou = dq.front();
        shou = '0' + shou;
        string wei = dq.back();
        wei = '0' + wei;
        long long aa = 0, bb = 0;
        int l1 = shou.size() - 2;
        int l2 = wei.size() - 2;
        for(int i = 1;i <= l1;i++)
            aa += (shou[i] - '0') * pingfang[l1 - i];
        for(int i = 1;i <= l2;i++)
            bb += (wei[i] - '0') * pingfang[l2 - i];
        if(aa < bb || aa == bb)
        {
            if(shou[l1 + 1] == wei[l2 + 1])
            {
                dq.pop_front();
                dq.pop_back();
                long long sheng = bb - aa;
                string s = "";
                long long t = sheng;
                while(t)
                {
                    int ge = t % 10;
                    char sh = ge + '0';
                    s += sh;
                    t /= 10;
                }
                s += wei[l2 + 1];
                if(sheng == 0) continue;
                else
                    dq.push_back(s);
            }
            else
            {
                dq.pop_front();
                dq.pop_back();
                int sheng = bb - aa;
                ans += aa;
                string s = "";
                long long t = sheng;
                while(t)
                {
                    int ge = t % 10;
                    char sh = ge + '0';
                    s += sh;
                    t /= 10;
                }
                s += wei[l2 + 1];
                if(sheng == 0) continue;
                else
                    dq.push_back(s);
            }
        }
        else
        {
            if(wei[l2 + 1] == shou[l1 + 1])
            {
                dq.pop_front();
                dq.pop_back();
                int sheng = aa - bb;
                string s = "";
                long long t = sheng;
                while(t)
                {
                    int ge = t % 10;
                    char sh = ge + '0';
                    s += sh;
                    t /= 10;
                }
                s += shou[l1 + 1];
                if(sheng == 0) continue;
                else
                    dq.push_front(s);
            }
            else
            {
                dq.pop_front();
                dq.pop_back();
                int sheng = aa - bb;
                ans += bb;
                string s = "";
                long long t = sheng;
                while(t)
                {
                    int ge = t % 10;
                    char sh = ge + '0';
                    s += sh;
                    t /= 10;
                }
                s += shou[l1 + 1];
                if(sheng == 0) continue;
                else
                    dq.push_front(s);
            }
        }
    }
    cout << ans;
    return 0;
}
