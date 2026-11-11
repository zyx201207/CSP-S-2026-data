#include <bits/stdc++.h>
using namespace std;

long long n,b[10000005];
long long sum,mid;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long cur = 1;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        char c;
        cin >> c;
        b[cur] = c - 'a' + 1;
        cur++;
    }
    cur--;
    long long step = 0;
    for(int i = 1;i <= cur / 2;i++)
    {
        cout << i << " " << b[i] << " " << cur-i+1 << " " << b[cur-i+1] << endl;
        if(b[i] != b[cur-i+1])
        {
            step++;
        }
    }
    cout << step;
    return 0;
}
