#include <bits/stdc++.h>
using namespace std;

int lastPos[500001];
int ans[500001];
vector<long long int> nums;
long long int n, m;

void di(int re)
{
    if (re < 0) return;
    vector<long long int> t= nums;

    for (int i = re;i < n;i++)
    {
        if (lastPos[t[i]] != i)
        {
            int lpti = lastPos[t[i]];
            for (int j = i;j < lpti;j++)
            {
                t[j] = 0;

            }

            i = lpti;

        }

    }

    int tstart = re;
    for (tstart = re-1;tstart > 0;tstart--)
    {
        if (nums[tstart] != nums[re]) break;
    }
    int cha = re - tstart;

    for (int i = re;i < n;i++)
    {
        ans[t[i]] += cha;

    }

    di(tstart);

}

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >>m;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        lastPos[x] = i;
        nums.push_back(x);
    }

    di(n-1);

    for (int i = 1;i <= m;i++)
    {

        cout << ans[i] << ' ';
    }

    return 0;
}
