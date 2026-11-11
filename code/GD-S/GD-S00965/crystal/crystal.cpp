#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],t;
bool is_a=1,is_b=1;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			is_a=0;
		}
	}
	t=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		if(abs(a[i]-a[i-1])!=t){
			is_b=0;
			break;
		}
	}
	if(is_b||is_a){
		ll sum=1,t1=0;
		while(m>=t1){
			t1+=t;
			m-=t1;
			sum++;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ll k=m;
	ll sum=1,ans=-1;
	for(int i=1;i<=n;i++){
		k=m;
		sum=1;
		for(int j=i+1;j<=n;j++){
			if(k>=a[i]-a[j]){
				sum++;
				k-=a[i]-a[j];
				
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
