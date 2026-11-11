#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll d[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+n+1); //O(nlogn)
    for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        ll sum=0;
        for(int j=1;j<=n;j++) d[j]=abs(a[i]-a[j]);
        sort(d+1,d+n+1);
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            sum+=d[j];
            if(sum>m) break;
            cnt++;
        }
        maxx=max(maxx,cnt);
    }
    cout <<maxx;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
