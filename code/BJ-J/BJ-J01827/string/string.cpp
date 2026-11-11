#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long cnt = 0;
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l = 1, r= n;
    while(l < r)
    {
        int t = min(a[l], a[r]);
        if(c[l] != c[r])cnt += t;
        a[l] -= t;
        a[r] -= t;
        if(a[l] == 0)l++;
        if(a[r] == 0)r--;
    }
    cout<<cnt;
    return 0;
}