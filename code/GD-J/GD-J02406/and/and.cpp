#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans,dp[200005][1000];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)
		ans=(ans&a[i]);
	cout<<ans;
	return 0;
} 
