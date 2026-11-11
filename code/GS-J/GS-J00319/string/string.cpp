#include <bits/stdc++.h>

using namespace std;

int a,ans;
char c;
deque<char> q;

int main()
{
    freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
    int n;
    cin >> n;
    if ( n == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        cin >> c;
        for (int j = 1; j <= a; j++)
        {
            q.push_back(c);
        }
    }
    while (!q.empty())
    {
    	if (q.front()  !=  q.back())
	    {
	        ans++;
	        q.pop_back();
	        q.pop_front();
	    }
	    else
	    	continue;
	}
    cout << ans;
    return 0;
}
