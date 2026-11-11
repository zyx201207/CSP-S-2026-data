#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long n, num = 0;;
    cin >> n;
    int a[n];
    char c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
        num += a[i];
    }
    int ad = 0, ab = 0, cnt = 0;
    char l[num];
    for(int i = 0; i < num; i ++)
    {
        l[i] = c[ad];
        ab ++;
        if(ab >= a[ad])
        {
            ab = 0;
            ad ++;
        }
    }
    char la[num / 2], lb[num /2];
    for(int i = 0; i < num / 2; i ++)
    {
        la[i] = l[i];
    }
    if(num % 2 == 0)
    {
        for(int i = num / 2 + 1; i <= num; i ++)
        {
            lb[i] = l[i];
        }
    }
    else
    {
        for(int i = num / 2 + 1; i <= num; i ++)
        {
            lb[i] = l[i];
        }
    }

    for(int i = 0; i < num/2; i ++)
    {
        if(la[i] != lb[i])
        {
            cnt ++;
        }
    }
    cout << cnt;

    return 0;
}
