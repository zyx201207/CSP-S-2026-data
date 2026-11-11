#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
long long a[MAXN],s[MAXN];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) s[i] = s[i-1]+a[i];
    int j = 1,ans = 1;
    for(int i = 1;i <= n;i++)
    {
        //if(i == 3) cout << "???" << a[i]*(i-j+1) << " " <<  s[i]-s[j-1]+m << endl;
        while(j <= n && a[i]*(i-j+1) > s[i]-s[j-1]+m) j++;
        //cout << i << " " << j << endl;
        ans = max(ans,i-j+1);
    }
    cout << ans;
    return 0;
}
