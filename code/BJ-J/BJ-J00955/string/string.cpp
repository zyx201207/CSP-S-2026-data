#include <bits/stdc++.h>
using namespace std;

int n,num;
long long sum,cnt;
char c,s[1000000005];


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i ++)
    {
        cin >> num >> c;
        for (int j = sum + 1;j <= sum + 1 + num;j ++)
        {
            s[j] = c;
        }
        sum += num;
    }
    for (int i = 1;i <= sum / 2;i ++)
    {
        if (s[i] != s[sum+1-i])
        {
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
