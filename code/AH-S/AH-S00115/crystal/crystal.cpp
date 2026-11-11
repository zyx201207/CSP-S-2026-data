#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int a[N];
bool cmp(int a,int b)
{
    return a < b;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("crystal.err","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l = 1,r = n;
    int mid = (l + r) >> 1;
    cerr << mid;
    int sum = 0;
    sum += mid;
    for(int i = mid+1;i <= n;i++)
    {
        if(a[mid] != a[i])break;
        else sum++;
    }
    cout << sum-1;
    return 0;
}