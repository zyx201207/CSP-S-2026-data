#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
long long n, m, ans[M], a[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >>n >>m;
    for (long long i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    for (long long t = 1; t <= n; t++)
    {
        vector<long long> v;
        for (long long i = t; i <= n; i++)
        {
            for (long long j = 0; j < v.size(); j++)
            {
                if (a[i] == v[j])
                {
                    long long k = v.size() - j;
                    while(k--) v.pop_back();
                }
            }
            v.push_back(a[i]);
        }
        for (long long i = 0; i < v.size(); i++) ans[v[i]]++;
    }
    for (long long i = 1; i <= m; i++) cout <<ans[i] <<' ';
    return 0;
}
