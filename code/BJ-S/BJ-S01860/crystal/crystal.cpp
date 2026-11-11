#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define fin freopen("crystal.in","r",stdin);
#define fout freopen("crystal.out","w",stdout);
using namespace std;
typedef long long lli;
int n,ans;
lli m;
lli a[500005];
int main()
{
    fin
    fout
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    lli need=0;
    for(int i=1,l=1;i<=n;i++)
    {
        if(i>1)
            need+=(i-l)*(a[i]-a[i-1]);
        while(l<i && need>m)
            need-=a[i]-a[l++];
        ans=max(ans,i-l+1);
    }
    cout << ans << endl;
    return 0;
}
