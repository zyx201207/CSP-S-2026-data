#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010],sum[200010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll j=i,t=m;
		while(t>0&&j>0){//cout<<t<<" ";
			j--;
			if(t>=a[j+1]-a[j]){
				t-=a[j+1]-a[j];
				sum[i]++;//cout<<sum[i]<<" ";
			}
			else{
				break;
			}
		}
		//cout<<t<<" ";
	}
	//for(int i=1;i<=n;i++){cout<<sum[i]<<" ";}
	sort(sum+1,sum+n+1,greater<ll>());
	cout<<sum[1];
	return 0;
} 
