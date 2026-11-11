#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int z = 1;z <= n;z++)
    {
        queue<int> tab;
        for (int i = z;i <= n;i++)
        {
            vector<int> temp;
            int k = a[i];
            while (!tab.empty() && tab.front() != k)
            {
                temp.push_back(tab.front());
                tab.pop();
            }
            while (!tab.empty()) tab.pop();
            for (int j = 0;j < temp.size();j++)
            {
                tab.push(temp[j]);
            }
            tab.push(k);
        }
        while (!tab.empty())
        {
            int tmp = tab.front();
            tab.pop();
            sum[tmp]++;
        }
    }
    for (int i = 1;i <= m;i++)
    {
        cout << sum[i] << " ";
    }
    return 0;
}
