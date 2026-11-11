#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,t1,t2,a[500010],sum[500010];
bool ab(long long a,long long b){
	if(a<0){
		if(a+m>=b){
			return true;
		}
		return false;
	}
	if(a>=b-m){
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	l=1,r=1;
	while(l<=n&&r<=n){
		t1=sum[r]-sum[l-1];
		t2=a[r]*(r-l+1);
		if(ab(t1,t2)){
			ans=max(ans,(r-l+1));
			++r;
		}
		else{
			++l;
		}
	}
	cout<<ans;
	return 0;
}
