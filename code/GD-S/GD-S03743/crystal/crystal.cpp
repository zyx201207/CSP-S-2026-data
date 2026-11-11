#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
ll a[N],m;
int n;
bool check(int len){
	ll sum=0;
	for(int x=0;x<len-1;x++)
		sum+=a[x];//,printf("+ %d %lld\n",a[x],sum);
	
	for(int l=0,r=len-1;r<n;sum+=a[r++]-a[l++]){
		if(a[r]*(len-1)-sum<=m)
			return 1;
//		printf("+ %d %lld\n",a[r],sum);
//		printf("- %d %lld\n",a[l],sum);
	}
	return 0;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int x=0;x<n;x++)
		cin>>a[x];
	sort(a,a+n);
	int l=2,r=n,ans=1;
	while(l<=r){
		const int mid=(l+r)>>1;
		//printf("check %d is%d\n",mid,(int)check(mid));
		if(check(mid))
			l=(ans=mid)+1;
		else
			r=mid-1;
	}
	cout<<ans;
}
/*
5 8
-3 -1 2 2 7
*/
