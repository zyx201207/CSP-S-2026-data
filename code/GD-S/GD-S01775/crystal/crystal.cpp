#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500005];
bool check(int x){
	//printf("%d",x);
	for(int i=x;i<=n;i++){
		int he=0;
		for(int j=i-x+1;j<i;j++){
			he+=a[i]-a[j];
		}
		if(he<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	while(l<r){
		ans=(r+l+1)/2;
		if(check(ans)){
			l=ans;
		}
		else{
			r=ans-1;
		}
		//printf("%d",ans);
	}
	//printf("%d %d %d %d",n,m,l,r);
	//for(int i=1;i<=n;i++) printf("%d",a[i]);
	printf("%lld",l);
	return 0;
} 
