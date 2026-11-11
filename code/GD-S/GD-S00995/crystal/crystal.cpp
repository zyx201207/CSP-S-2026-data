#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(m>1000000000){
		cout<<n;
		return 0;
	}
	sort(arr,arr+n);
	int ans=0,ge=1;
	long long da=0,z=0;
	for(int i=1;i<n;i++){
		z=z+arr[i]-arr[i-1];
		da=da+(arr[i]-arr[i-1])*ge;
		ge++;
		while(da>m){
			da=da-z;
			ge--;
			z=z-arr[i-ge+1]+arr[i-ge];
		}
		ans=max(ans,ge);
	}
	cout<<ans;
	return 0;
}
