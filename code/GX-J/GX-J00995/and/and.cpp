#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i]==a[i-1]||a[i]==a[i-2]||a[i]==a[i-3]||a[i]==a[i-4]||a[i]==a[i-5]||a[i]==a[i-6]||a[i]==a[i-7])
        {
            cout << a[i];
            return 0;
        }
    }
    cout << a[n];
    return 0;
}
