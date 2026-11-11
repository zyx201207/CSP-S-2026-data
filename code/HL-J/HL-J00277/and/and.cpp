#include<iostream>
#include<algorithm>
unsigned long long arr[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;std::cin>>n>>m;
	for(int i=1;i<=n;i++){std::cin>>arr[i];}
	std::sort(arr+1,arr+n+1);
	unsigned long long ans=0xffffffffffffffff;
	for(int i=1;i<=m;i++){
		ans&=arr[n-i+1];
	}std::cout<<ans;
return 0;}
