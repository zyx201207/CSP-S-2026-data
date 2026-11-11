#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int id = n, ans = 1;
    for(int i = a[n]; i >= a[1]; i--)
    {
        while(a[id] > i) id--;
        int j = id;
        long long cnt = 0;
        //cout << i << ' ' << id << endl;
        while(cnt <= m && j >= 1)
        {
            cnt += i-a[j];

            //cout << cnt << ' ' << j << endl;
            j--;
        }
        ans = max(ans, id-j-1+(j < 1 && cnt <= m ? 1 : 0));
        //cout << ans << endl;
        //cout << endl;
    }
    cout << ans;
    return 0;
}
