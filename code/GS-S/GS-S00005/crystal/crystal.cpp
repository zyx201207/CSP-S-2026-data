#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N],b[N];
int n,m;
int abss(int n)
{
    if (n >= 0){
        return n;
    }
    else{
        return -n;
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++){
        b[i] = abss(a[i] - a[i - 1]);
    }
    long long ans = 0;
    for (int i = 2;i <= n;i++){
            if (ans + b[i] * (i - 1) > m)
            {
                cout << i - 1;
                return 0;
            }
            else{
                ans += b[i] * (i - 1); 
            }
    }
    cout << n;
    return 0;
}
