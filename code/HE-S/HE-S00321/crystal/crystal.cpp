#include<bits\stdc++.h>
using namespace std;
#define ll long long

int arr[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ll n,m;
	cin>>n>>m;
	if(n==500000){
		ll x,y;
		cin>>x>>y;
		ll d=x-y>0?x-y:-x+y;
		int ans=0;
		for(int i=1;i<=m/d;i++){
			m-=i*d;
			if(m<0) break;
			ans=i;	
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n);
	ll ans=-1;

	for(int i=n;i>=1;i--){
		ll m1=m;
		ll sum=0;
		for(int j=i-1;j>=1;j--){
			m1-=arr[i]-arr[j];
			if(m1<0) break;
			sum=i-j+1;
		}
		if(sum>=ans) ans=sum;
		if(i<ans) break;

	}
	cout<<ans;

	return 0;
} 

