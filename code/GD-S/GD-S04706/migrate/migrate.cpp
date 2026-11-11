#include<bits/stdc++.h>
#define int long long
int c,T;
int n,d;
int a[1000010];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::cin>>c>>T;
	while(T--){
		std::cin>>n>>d;
		for(int i=1;i<=n;i++){
			std::cin>>a[i];
			if(a[1]<0) a[i]+=(-a[1]);
			else a[i]-=a[1];
		}
		if(n<=3||d==1){
			std::cout<<"0\n";
			continue;
		}
		int r=1;
		for(;r<=n;r++){
			if(a[r]%d) break;
		}
		std::cout<<(n/r+1)<<'\n';
	}
	return 0;
}//Thanks OI,hope you can enjoy your play in the past six years.
