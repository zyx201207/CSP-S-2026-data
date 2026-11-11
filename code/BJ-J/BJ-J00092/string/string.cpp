#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn];
char c[maxn];
int n;

void solve(){
    cin >> n;
    long long k = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        k += a[i];
    }
    long long ans = 0;
    int l = 1, r = n;
    long long mid = k / 2;
    long long cntl = 0;
    long long cntr = 0;
    while(cntl <= mid && cntr <= mid && l < r)
    {
        if(c[l] == c[r])
        {
            if(a[l] > a[r])
                {
                    a[l] -= a[r];
                    cntl += a[r];
                    cntr += a[r];
                    a[r] = 0;
                    r--;
                }
                else if(a[l] < a[r])
                {
                    a[r] -= a[l];
                    cntr += a[l];
                    cntl += a[l];
                    a[l] = 0;
                    l++;
                }
                else if(a[l] == a[r])
                {
                    cntl += a[l];
                    cntr += a[r];
                    a[r] = 0;
                    a[l] = 0;
                    l++;
                    r--;
                }
        }
        else
        {
                if(a[l] > a[r])
                {
                    a[l] -= a[r];
                    cntl += a[r];
                    cntr += a[r];
                    ans += a[r];
                    a[r] = 0;
                    r--;
                }
                else if(a[l] < a[r])
                {
                    a[r] -= a[l];
                    cntr += a[l];
                    cntl += a[l];
                    ans += a[l];
                    a[l] = 0;
                    l++;
                }
                else if(a[l] == a[r])
                {
                    cntl += a[l];
                    cntr += a[r];
                    ans += a[r];
                    a[r] = 0;
                    a[l] = 0;
                    l++;
                    r--;
                }
        }
    }
    cout << ans;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}
