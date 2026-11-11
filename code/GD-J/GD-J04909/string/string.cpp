#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
char ch[N];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        int a;
        char s;
        cin >> a >> s;
        for(int j = 1 ; j <= a ; i++)
        {
            ch[cnt + j] = s;
        }
        cnt += a;
    }
    int ans = 0;
    for(int i = 1 ; i <= (n + 1) / 2 ; i++)
    {
        if(ch[i] != ch[n - i + 1])
        {
        	ans++;
		}
    }
    cout << ans;
    return 0;
}

