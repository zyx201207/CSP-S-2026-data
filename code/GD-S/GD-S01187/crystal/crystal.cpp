#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll n,m,sum=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1,j=1;j<=n;j++){
		sum+=a[j];
		while(a[j]*(j-i)-(sum-a[j])>m && i<j){
			sum-=a[i];
			i++;
		}
		ans=max(ans,j-i+1);
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
