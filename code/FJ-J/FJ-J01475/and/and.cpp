#include<bits/stdc++.h>
using namespace std;
int n,m,nums[2005],sum;
int logtwo(int n){
	int q;
	while(n/2){
		n/=2;
		q++;
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	sort(nums+1,nums+n+1);
	for(int i=1;i<m;i++){
		sum+=logtwo(nums[n-i+1]);
	}
	cout<<sum;
	return 0; 
}
