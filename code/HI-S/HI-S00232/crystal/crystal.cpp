#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

long long n, m, a[N];
map<long long, int> b;
set<long long> ap;

int main() 
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
        ap.insert(a[i]);
    }
    int sum[N];
    for(int i : ap)
    {
        int mt = m;
        sum[i] = b[i];
        for(int j = 1; j <= n; j++)
        {
            if(b[i - j] * j <= mt)
            {
                sum[i] += b[i - j];
                mt -= b[i - j] * j;
            }
            else
            {
                sum[i] = mt;
                break;
            }
            if(b[i + j] * j <= mt)
            {
                sum[i] += b[i + j];
                mt -= b[i + j] * j;
            }
            else
            {
                sum[i] = mt;
                break;
            }
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max(sum[i], mx);
    cout << mx;
    return 0;
}