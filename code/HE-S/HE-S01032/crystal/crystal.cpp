#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	ll n,m,ans=0;
	ll a[100005]={};
	scanf("%lld %lld",&n,&m);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sum/=n;
	for(int i=0;i<n;i++){
		if(sum-a[i]>=0&&sum-a[i]<=m){
			m-=sum-a[i];
			ans++;
		}
		else if(a[i]-sum>=0&&a[i]-sum<=m){
			m-=sum-a[i];
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
