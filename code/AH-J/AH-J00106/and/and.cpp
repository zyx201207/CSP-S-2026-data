#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	int ans;
	int a[200005],dp[200005];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&dp[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=a[i-1]&a[i];
			dp[j]=max(dp[j],ans);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
