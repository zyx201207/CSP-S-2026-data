#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int n;
string s;
char lf[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    s = "";
    long long cnt = 0;
    for(int i = 1;i <= n;++i)
    {
        long long num;
        char ch;
        cin >> num >> ch;
        for(int i = cnt + 1;i <= cnt + num;++i)
        {
            lf[i] = ch;
        }
        cnt += num;
    }
    long long ans = 0;
    long long pos = cnt / 2 + 1;
    for(int i = 1;i < pos;i++)
    {
        if(lf[i] != lf[cnt  +  1 - i]) ans++;
    }
    cout << ans;


    return 0;
}
