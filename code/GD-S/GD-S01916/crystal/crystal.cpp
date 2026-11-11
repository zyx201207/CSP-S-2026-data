#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[505050];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxl=-1;
	ll sum=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",a+i);
	}
	sort(a,a+n,greater<ll>());
	for(int i=0,j=1;i<n&&j<n;i++){
		while(j<n&&sum-a[j]+a[i]<=m) sum+=a[i]-a[j++];
		maxl=max(maxl,j-i);
		//printf("%lld\n",sum);
		sum-=(j-i-1)*(a[i]-a[i+1]);
	}
	printf("%d",maxl);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
