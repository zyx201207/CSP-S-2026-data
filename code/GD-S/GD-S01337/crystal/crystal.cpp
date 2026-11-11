#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
bool check(int lim){
	long long s=0;
	for(int i=1;i<=lim-1;i++)
		s+=a[i];
	for(int i=lim;i<=n;i++)
	{
		s+=a[i]-a[i-lim];
		if((long long)a[i]*lim-s<=m)return true;
	}
	return false;
}
int solve(){
	int l=1,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	printf("%d",solve());
	return 0;
}
