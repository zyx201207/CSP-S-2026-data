#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
string tem = "000000000000000000000000000000", two[maxn];
string ans = "111111111111111111111111111111";
void change(int pos, int x)
{
    int tot = -1;
    while(x)
    {
        tem[++tot] = char('0' + (x & 1));
        x >>= 1;
    }
    for(int i = tot; i >= 0; i--) two[pos][29 - i] = tem[i];
}
bool cmp(string a, string b)
{
    if(a == b) return true;
    for(int i = 0; i < 30; i++)
    {
        if(a[i] != b[i])
        {
            if(a[i] == '1') return true;
            else return false;
        }
    }
}
void calculate(char &x, char &y)
{
    if(x == '1' && y == '1')return;
    x = '0';
}
int main()
{
    freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        two[i] = "000000000000000000000000000000";
        int x;
        cin >> x;
        change(i, x);
    }
    sort(two + 1, two + n + 1, cmp);
    for(int i = 1; i <= m; i++)
        for(int j = 0; j < 30; j++)
            calculate(ans[j], two[i][j]);
    int ten = 1, num = 0;
    for(int i = 29; i >= 0; i--)
    {
        num += (int)(ans[i] - '0') * ten;
        ten *= 2;
    }
    cout << num;
    return 0;
}

