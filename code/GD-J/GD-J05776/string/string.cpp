#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int x;
    char c;
};
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, len = 0, res = 0;
    deque<Node> dq;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        len += x;
        dq.push_front(Node{x, c});
    }
    while (dq.size() > 1)
    {
        if (dq.back().x == dq.front().x && dq.back().c == dq.front().c)
        {
        	if (dq.size() == 1)
        		continue;
            dq.pop_back();
            dq.pop_front();
            continue;
        }
        if (dq.back().x == dq.front().x)
        {
            res += dq.back().x;
            dq.pop_back();
            dq.pop_front();
        }
        else if (dq.back().x < dq.front().x) // dq.front() > dq.back()?
        {
        	if (dq.back().c != dq.front().c)
            	res += dq.back().x;
            Node tmp = dq.front();
            tmp.x = dq.front().x - dq.back().x;
            dq.pop_back();
            dq.pop_front();
            dq.push_front(tmp);
        }
        else // dq.front() < dq.back()?
        {
        	if (dq.back().c != dq.front().c) 
            	res += dq.front().x;
            Node tmp = dq.back();
            tmp.x = dq.back().x - dq.front().x;
            dq.pop_front();
            dq.pop_back();
            dq.push_back(tmp);
        }
    }
    cout << res << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
