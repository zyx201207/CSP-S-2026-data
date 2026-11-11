#include <bits/stdc++.h>
using namespace std;
vector<int> d, z, c;
int suma[300010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    c.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        c.push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        //cout << "new game!\n";
        d.clear();
        for (int j = 1; j <= n; j++)
        {
            d.push_back(c[j]);
        }
        z.clear();
        z.push_back(0);
        for (int j = i-1; j <= n; j++)
        {
            //cout << "table:";
            //for (auto txt:z)
            //{
            //    cout << txt << " ";
            //}
            //cout << endl << "dui:";
            //for (auto txt2:d)
            //{
            //    cout << txt2 << " ";
            //}
            //cout << "\n";
            bool flag = false;
            int fi;
            for (int k = 1; k <= z.size()-1; k++)
            {
                if (z[k] == d[j])
                {
                    flag = 1;
                    fi = k;
                }
            }
            if (flag)
            {
                z.erase(z.begin()+fi, z.end());
                //cout << "erase ok!\n";
            }
            z.push_back(d[j]);
        }
        for (auto t:z)
        {
            for (int o = 1; o <= m; o++)
            {
                if (t == o)
                {
                    suma[o]++;
                }
            }
        }
    }
    for (int ans = 1; ans <= m; ans++)
    {
        cout << suma[ans] << " ";
    }
    return 0;
}
