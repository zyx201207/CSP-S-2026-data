#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
map<ll,char> qwq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll sum=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
		if(i==1){
			for(ll j=1;j<=a[1];j++){
				qwq[j]=c[i];
			}
		}else{
			for(ll j=sum-a[i]+1;j<=sum;j++){
				qwq[j]=c[i];
			}
		}
	}
	ll ans=0;
	if(sum%2==0){
		for(ll i=sum/2;i>=1;i--){
			if(qwq[i]!=qwq[sum-i+1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(sum%2==1){
		for(ll i=(sum-1)/2;i>=1;i--){
			if(qwq[i]!=qwq[sum-i+1]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
//	ll awa=0;
//	char quq;
//	if(sum%2==0){
//		ll sum1=a[1];
//		ll qwq=0;
//		for(int i=2;i<=n;i++){
//			sum1+=a[i];
//			if(sum1>sum/2){
//				qwq=i-1;
//				sum1-=a[i];
//				a[i]=a[i]-(sum/2-sum1);
//				quq=c[i];
//				break;
//			}
//		}
//		awa=sum/2-sum1;
//		
//		
//	}if(sum%2==1){
//		
//	}

	return 0;
}

