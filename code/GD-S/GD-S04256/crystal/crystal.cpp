#include<bits/stdc++.h>

#define problem(prob) freopen(#prob ".in","r",stdin),freopen(#prob ".out","w",stdout)
#define stm() std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)

int n,m,a[500005];

int main(){
	problem(crystal);
	stm();
	
	std::cin>>n>>m;
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	std::sort(a,a+n);
	
	int chosed=1;
	int used=0;
	int ans=0;
	
	for(int i=1;i<n;i++){
		used+=chosed*(a[i]-a[i-1]);
		while(used>m){
			used-=a[i]-a[i-chosed];
			chosed--;
		}
		chosed++;
		ans=std::max(chosed,ans);
	}
	
	std::cout<<ans;
	
	return 0;
} 
