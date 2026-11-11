#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
long long a[500010];
long long sum=0,m;
int ans=1;
int h=1,t=0;
int q[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[++t]=i;
		sum+=a[i];
		while(h<=t&&(t-h+1)*a[i]>sum+m){
			sum-=a[q[h++]];
		}
		ans=max(ans,t-h+1);
	}
	cout<<ans;
	return 0;
}
