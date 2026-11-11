#include<bits/stdc++.h>
using namespace std;

struct st
{
    string s;
};

const int maxn = 1e6 + 5;
int a[maxn];
st er[maxn];
int n, m;
int k;

bool cmp(st x, st y)
{
    return x.s[k] > y.s[k];
}

void solve(){
    cin >> n >> m;
    int maxx = -1e9;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(m == 1)
    {
        cout << maxx;
    }
    if(m == n)
    {
        k = a[1];
        for(int i = 1;i <= n;i++)
        {
            k = k & a[i];
        }
        cout << k;
    }
    if(m == 2)
    {
        maxx = -1e9;
        for(int i = 1;i <= n - 1;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                maxx = max(maxx, a[i] & a[j]);
            }
        }
        cout << maxx;
    }
    if(m == n - 1)
    {
        maxx = -1e9;
        for(int i = 2;i <= n;i++)
        {
            k = a[1];
            for(int j = 2;j <= n;j++)
            {
                if(j != i) k = k & a[j];
            }
            maxx = max(maxx, k);
        }
        k = a[2];
        for(int i = 3;i <= n;i++)
        {
            k = k & a[i];
        }
        maxx = max(maxx, k);
        cout << maxx;
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
