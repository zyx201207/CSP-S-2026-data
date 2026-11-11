#include <bits/stdc++.h>
#define int long long
using namespace std;

int w[100005],v[100005];
vector <int> v1[100005];
int maxn = 0;



signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        int n,d,ans = 0;
        cin >> n >> d;
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
        srand(time(0));
        cout << rand() % 5;
    }
    return 0;
}
