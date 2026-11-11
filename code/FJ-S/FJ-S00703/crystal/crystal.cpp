#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m;
long long arr[N];
long long sum[N];
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	long long left=1,right=2;
	while(right<n){
		long long he=arr[right]*(right-left)-(sum[right-1]-sum[left-1]);
//		cout<<left<<" "<<right<<" "<<he<<"\n"; 
		if(he<=m){
			ans=max(ans,right-left);
			right++;
		}else{
			left++;
			if(left==right){
				right++;
			}
		}
	}
	cout<<ans+1;
	return 0;
} 
