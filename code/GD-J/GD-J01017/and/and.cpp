#include<bits/stdc++.h>
using namespace std;
int m,nums[200002],n,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	sort(nums,nums+n);
	ans=nums[n-1];
	for(int i=n-1;i>=n-m;i--){
		ans=(ans&nums[i]);
	}
	cout<<ans;
	cout<<endl;
	return 0;
}
