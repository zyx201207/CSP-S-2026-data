//#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n, m, ans[M], a[N];
//vector<int> a;
int main()
{
    cin.tie(0); cout.tie(0);
    cin.sync_with_stdio(0); cout.sync_with_stdio(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
//        int tmp;
//        cin >> tmp;
//        a.push_back(tmp);
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (int j = i; j < n; j++)
        {
            bool flag = 0;
            for (int k = 0; k < tmp.size(); k++)
            {
                if (a[j] == tmp[k])
                {
                    flag = 1;
                    for (int l = k; l < tmp.size(); l++)
                    {
                        tmp[l] = -1;
//                        tmp.push_back(a[j]);
                    }
                    tmp.push_back(a[j]);
                    break;
                }
            }
            if (!flag)
            {
                tmp.push_back(a[j]);
            }
//            if (flag)
//            {
//                for(int k = )
//            }
        }
//        for (int j = 1; j <= m; j++)
//        {
        for (int k = 0; k < tmp.size(); k++)
        {
//            if ()
            if (tmp[k] != -1)
            {
                ans[tmp[k]]++;
            }
        }
//        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}
