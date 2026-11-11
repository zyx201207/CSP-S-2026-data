#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void quick_oi()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie();
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second > b.second;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        int k = a[i].first;
        int ans = 0;
        while (k != 0)
        {
            ans += (k & 1);
            k = k >> 1;
        }
        a[i].second = ans;
    }
    sort(a.begin()+1,a.end(),cmp);
    int anss = -1;
    for(int i = 1; i <= m ; i++)
    {
        if(anss == -1)
        {
            anss = a[i].first;
        }
        else
        {
            anss = anss & a[i].first;
        }
    }
    cout << anss;
    return 0;
}