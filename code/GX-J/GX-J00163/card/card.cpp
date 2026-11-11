#include<bits/stdc++.h>
using namespace std;

int findd(int d[], int len, int num)
{
    for(int i = 1; i <= len; i++)
    {
        if(d[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int a[500005], cnts[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int top = 1;
        int d[500005] = {0};
        for(int j = i; j <= n; j++)
        {
            int k = a[j];
            if(findd(d, top, k) == -1)
            {
                d[top + 1] = k;
                top++;
            }
            else
            {
                top = findd(d, top, k);
            }
        }
        for(int j = 1; j <= m; j++)
        {
            if(findd(d, top, j) != -1)
            {
                cnts[j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << cnts[i] << ' ';
    }

    return 0;
}
