#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m;
ll a[500005];
int flag=1,d=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(d==-1&&i==2){
			d=a[i]-a[i-1];
		}else if(a[i]-a[i-1]!=d){
			flag=0;
		}
	}
	if(flag){
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans+=abs(d*i);
			if(ans>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=i;
		ll sum=0;
		for(;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				break;
			}
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
