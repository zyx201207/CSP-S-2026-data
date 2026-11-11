#include<bits/stdc++.h>
using namespace std;
unsigned long long n, a[200010], r, i, j, tl, tr, ans;
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(unsigned long long i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
        r+=a[i];
    }
    unsigned long long l=1;
    i=1;
    j=n;
    tl=a[1];
    tr=a[n];
    while(l<=r)
    {
        if(c[i]!=c[j]) ans++;
        if(tl==1)
        {
            i++;
            tl+=a[i];
        }
        if(tr==1)
        {
            j--;
            tr+=a[j];
        }
        tl--;
        tr--;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}