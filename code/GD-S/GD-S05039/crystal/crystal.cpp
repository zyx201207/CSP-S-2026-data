#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int i=n-1,j=n;
	ll sheng=m,ans=0,now=1;
	while(i>=1&&j>=i)
	{
		if(sheng>=a[j]-a[i])
		{
			sheng-=(a[j]-a[i]);
			now=j-i+1;
			ans=max(ans,now);
			i--;
		}
		else
		{
			sheng+=(now-1)*(a[j]-a[j-1]);
			now--;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

