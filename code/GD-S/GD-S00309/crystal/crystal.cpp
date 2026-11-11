#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m;
ll a[500005];
bool check(int mid){
	ll sum=0;
	for(int i=1;i<=mid;i++){
		sum+=a[i];
	}
	ll mn=1e18;
	for(int i=mid;i<=n;i++){
		mn=min(mn,a[i]*mid-sum);
		sum-=a[i-mid+1];
		sum+=a[i+1];
	}
	return mn<=m;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}
