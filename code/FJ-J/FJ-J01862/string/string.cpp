#include <bits/stdc++.h>
std::string kkkk;
int main(){
	std::frepoen("string.in","r",stdin);
	std::freopen("string.out","w",stdout);
	int n;
	std::cin>>n;
	int kkp=0;
	long long sum=0;
	int cnt;
	char kk; 
	if(n==1){
		std::cout<<0;
		return 0;
	}	
	
	for(int i=1;i<=n;i++){
		std::cin>>cnt>>kk;
		for(int j=1;j<=cnt;j++) {
			kkkk+=kk;
		}
		sum+=cnt;
	} 

	for(int i=0;i<=sum/2;i++){
		if(kkkk[i]!=kkkk[n-i+1]){
			kkp++;
		}
	}
	
	std::cout<<kkp;
	return 0;
}
