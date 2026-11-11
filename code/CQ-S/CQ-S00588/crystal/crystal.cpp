#include<bits/stdc++.h>
#define N 500005
typedef long long ll;
using namespace std;
ll n,arr[N],m,a[N],ans;
bool flaga,flagb;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+n);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i-1]+(arr[i]-arr[i-1])*i*1LL;
		if(m>=a[i])ans=i+1;
	}
	printf("%lld",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
