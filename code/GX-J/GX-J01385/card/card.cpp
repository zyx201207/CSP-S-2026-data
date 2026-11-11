#include <bits/stdc++.h>
using namespace std;
stack(int) s;
int n,m,a[200005],b[200005];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s.push(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cout << s.top();
        s.out();
    }
    return 0;
}
