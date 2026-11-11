#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
ll n,m;
ll a[N];
ll ans,maxn=LONG_LONG_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1)ans=a[i];
		if(i<n-1)ans&=a[i+1];
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(m==2){
		cout<<(a[1]&a[2]);
		return 0;
	}
	else if(m==n-1){
		cout<<ans;
		return 0;
	}
	else ans=0;
	for(int i=1;i<m;i++){
		a[i+1]&=a[i];  
	}
	printf("%lld",a[m]);
	return 0;
}
/*
5 3
31 3 1 15 7
*/
