#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int n,m,a[N];
int q[2*N];

bool check(int x)
{
    int head=1,tail=1;
	int sum=0,maxn=a[x-1];
	for(int i=1;i<=x-1;i++) q[tail++]=a[i],sum+=a[x-1]-a[i];
	for(int i=x;i<=n;i++)
    {
        q[tail++]=a[i];
        sum+=(a[i]-maxn)*(x-1);
        if(sum<=m) return 1;
        sum-=a[i]-q[head];
        head++;
        maxn=a[i];
    }
    return 0;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << ans;
	return 0;
}

