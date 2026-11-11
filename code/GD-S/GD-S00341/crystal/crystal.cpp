#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10; 
ll n,m;
ll a[N];
ll ans[N],top=0;//答案栈
ll max_=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m>100000000){ //特殊性质AB 
		ll cb=a[2]-a[1]; //差比 
		ll cnt=0;
		for(ll i=cb;1;i+=cb){
			m-=i;
			if(m>=0){
				cnt++;
			}else{
				cout<<cnt;
				return 0;
			}
		}
	}
	for(ll i=1;i<=n;i++){
		if(i>=2&&a[i]==a[i-1]){
			ans[top]++;
			//cout<<ans[top]<<" "; 
			max_=max(max_,ans[top]);
			continue;
		}
		top++;
		ll tp=m;
		for(ll j=i;j>=1;j--){
			if(tp>=a[i]-a[j]){
				tp-=(a[i]-a[j]);
				ans[top]++;
			}else{
				break;
			}
		}
		//cout<<ans[top]<<" "; 
		max_=max(max_,ans[top]);
	}
	cout<<max_;
	return 0;
}
