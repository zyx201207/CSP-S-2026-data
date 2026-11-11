#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[500005],n,m,ans=-1;
ll f(ll k){
	stack<ll>st;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			while(a[i]==k){
				cnt++;
				i++;
			}
			break;
		}
		st.push(k-a[i]);
	}
	ll p=0;
	while(p<=m && !st.empty()){
		p+=st.top();
		if(p<=m){
			cnt++;
		}
		st.pop();
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll k;
	bool tsxz=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2){
			k=a[2]-a[1];
		}else if(i>2 && tsxz){
			if(a[i]-a[i-1]!=k){
				tsxz=0;
			}
		}
	}
	if(tsxz){
		ll p=0,i=1;
		while(p<=m && i<n){
			p+=k*i;
			if(p<=m){
				i++;
			}
		}
		printf("%lld",i);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=max(ans,f(a[i]));
	}
	printf("%lld",ans);
	return 0;
} 
