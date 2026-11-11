#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
    int n,a[1000010],f,s,t;
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 1;i <= n;i ++)
    {
        f = max(a[i],max(a[i+1],a[i+2]));
        s = max(a[i],max(f,a[i+2]));
        t = max(a[i],min(a[i+1],a[i+2]));
        if(i == n-2)
            break;
    }
    cout << t;
    return 0;
}
