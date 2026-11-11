#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c ; ++a)
using namespace std;
int a[200005],bz[200005],zy[34];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    lop(i,0,33) zy[i]=(1ll<<i);
	int n,m;
    cin >> n >> m;
    loop(i,n)
    {
        cin >> a[i];
    }
    int ans=0;
    for (int k=30;k>=0;--k)
    {
        int cnt=0;
        loop(i,n)
        {
            if (!bz[i]&&(a[i]&zy[k])!=0) cnt++;
        }
        if (cnt<m) continue;
        ans+=zy[k];
        loop(i,n)
        {
            if ((a[i]&zy[k])==0) bz[i]=1;
        }
    }
    cout << ans << endl;
	return 0;
}
