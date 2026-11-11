#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500007];
int c[500007];
int cha[500007];
bool check(int len){
	bool flag=0;
	int mn=1e18;
	for(int i=1;i<=n;i++){
		int man=(i-1)*(a[i+len-1]-a[i]);
		if(i+len-1>n){
			break;
		}
		if(c[i+len-1]-c[i]-man<=m&&c[i+len-1]-c[i]-man>=0){
			flag=1;
			break;
		}
		mn=min(mn,c[i+len-1]-c[i]);
	}
	return flag;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+1LL*(a[i]-a[i-1])*1LL*(i-1);
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%lld",l);
	return 0;
}
