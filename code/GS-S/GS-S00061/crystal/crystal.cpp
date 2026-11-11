#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5+5;
int n;
ll m,a[MAXN];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l = 1;
    ll now = 0;
    for(int i = 1;i<=n;i++)
    {
        now+=(i-l)*(a[i]-a[i-1]);
        while(now>m)
        {
            now-=a[i]-a[l];
            l++;
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}