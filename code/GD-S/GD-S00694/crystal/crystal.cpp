#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500015],s[500015];
bool check(int x){
	int k=LLONG_MAX;
	for(int i=x;i<=n;i++){
		int t=a[i]*x-s[i]+s[i-x-1];
		k=min(k,t);
	}
	return (k<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid,ans;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
