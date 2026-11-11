
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N] , dic[N] , ans[N];
vector<int> v;

int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        while(!v.empty())
        {
            v.pop_back();
        }
        for (int j = i;j <= n;j++)
        {
            int pos = 0;
            if (dic[a[j]])
            {
                for (int k = 0;k < v.size();k++)
                {
                    if (v[k] == a[j])
                    {
                        pos = k;
                        break;
                    }
                }
                for (int k = 0;k < v.size();k++)
                {
                    dic[v[k]]--;
                    v.pop_back();
                }
                v.push_back(a[j]);
                dic[a[j]]++;
            }
            else
            {
                v.push_back(a[j]);
                dic[a[j]]++;
            }
        }
        for (int j = 0;j < v.size();j++)
        {
            if (v[j] == i)
            {
                ans[i]++;
            }
        }
    }
    for (int i = 1;i <= m;i++)
    {
        if (ans[i])
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
