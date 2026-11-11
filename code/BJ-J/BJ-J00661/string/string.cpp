#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
struct T
{
    int cnt;
    char c;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out,"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i].cnt>>a[i].c;
    ll ans=0;
    int l=1,r=n;
    while (l<r)
    {
        if (a[l].cnt<=a[r].cnt)
        {
            a[r].cnt-=a[l].cnt;
            if (a[l].c==a[r].c)
                a[l].cnt=0;
            ans+=a[l].cnt;
            l++;
        }
        else
        {
            a[l].cnt-=a[r].cnt;
            if (a[l].c==a[r].c)
                a[r].cnt=0;
            ans+=a[r].cnt;
            r--;
        }
    }
    cout<<ans;
    return 0;
}