#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,maxl=1e3+10; 
int n,m;
int ans=0;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int sum=a[1];
	for(int i=2;i<=n;i++) sum&=a[i];
	if(m==1) return cout<<a[1],0;
	if(m==n) return cout<<sum,0;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i];
		for(int j=i+1;j<=n-1;j++) sum=max(sum&a[j],sum&a[j+1]);
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
