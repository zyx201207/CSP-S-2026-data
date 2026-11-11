#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long m,sum,a[N],ans,n,cnt;
queue<long long> q;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long cf=a[i]-a[i-1];
		while(sum+cnt*cf>m)
		{
			sum-=a[i-1]-q.front(); 
			q.pop(),cnt--;
		} 
		q.push(a[i]),sum+=cnt*cf,cnt++;
		ans=max(ans,cnt);
//		cout<<i<<' '<<cnt<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
} 
