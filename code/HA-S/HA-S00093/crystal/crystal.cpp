#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[500005];
bool check(long long mid){
	long long an=0;
	for(int i=1;i<=n;i++){
		if(arr[i]<mid){
			an+=(mid-arr[i]);
		}
		if(an>m){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long mi=1e12,mx=-1e12;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<mi){
			mi=arr[i];
		}
		if(arr[i]>mx){
			mx=arr[i];
		}
	}
	long long l=mi,r=mx,ans=0;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(arr[i]<=l){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
