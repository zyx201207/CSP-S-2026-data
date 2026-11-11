#include<iostream>
#include<algorithm>
#include<cmath>
long long arr[500001],art[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	int n,m;std::cin>>n>>m;
	bool markA=true,markB=true;
	for(int i=1;i<=n;i++){
		std::cin>>arr[i];
	}std::sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		art[i]=art[i-1]+arr[i];
	}int l=1,maxt=0;
	for(int r=1;r<=n;r++){
		while(arr[r]*(r-l+1)-(art[r]-art[l-1])>m){
			l++;
		}
		maxt=std::max(maxt,r-l+1);
	}
	std::cout<<maxt;
return 0;}
