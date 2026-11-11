#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5 + 10;
int n,l;
LL m,a[N],d[N],c[N],w;
LL book[N],maxb = -1;
deque <LL> de;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    sort(a+1,a+1+n);

    for(int i = 2;i <= n;++i)
        d[i] = a[i] - a[i-1];
    for(int i = 2;i <= n;++i)
        c[i] = c[i-1] + d[i];

    de.push_front(a[1]);
    l = 1;
    for(int i = 2;i <= n;i++)
    {
        de.push_front(a[i]);
        w += d[i] * (de.size() - 1);
        while(w > m)
        {
            de.pop_back();
            w -= c[i] - c[l];
            ++l;
            if(w <= m) break;
        }
        book[i] = (m == 0 || de.size() == 1) ? 0 : de.size();
    }
    for(int i = 2;i <= n;i++)
        maxb = max(maxb,book[i]);
    cout << maxb;
    return 0;
}
