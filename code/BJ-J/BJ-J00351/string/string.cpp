#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long lstl,lstr,l,r,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
    }
    l=1,r=n;
    lstl=a[1],lstr=a[n];
    for (int i=1;i<=n;i++)
    {
        long long t=min(lstl,lstr);
        if (c[l]!=c[r]) ans+=t;
        lstl-=t,lstr-=t;
        if (lstl==0)
        {
            lstl=a[++l];
        }
        else
        {
            lstr=a[--r];
        }
        if (l>=r) break;
    }
    cout << ans << endl;
    return 0;
}