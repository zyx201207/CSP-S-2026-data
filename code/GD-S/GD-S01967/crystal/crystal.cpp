#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=5*1e5+10;
ll n,m;
ll arr[MAXN],sum[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	} 
	
	ll u=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ll pos=1ll*(i-j+1);
			ll cost=arr[i]*pos-(sum[i]-sum[j-1]);
			if(cost<=m && u<pos){
				u=pos;
			}
		}
	}
	
	cout<<u;
	
	return 0;
} 
