#include<bits/stdc++.h>
#define int long long
#define fre freopen("and.in","r",stdin),freopen("and.out","w",stdout)
using namespace std;
const int MAXN=2e5+34;
int n,m,a[MAXN],x;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fre,cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int d=31,cnt=0;d>0;x|=(1<<(d-1))*(cnt>=m),d--,cnt=0)
	{
		for(int i=1;i<=n;i++) cnt+=((a[i]>>(d-1))&1);
		if(cnt>=m) for(int i=1;i<=n;i++) if(((a[i]>>(d-1))&1)^1) a[i]=0;
	}
	cout<<x;
	return 0;
}
