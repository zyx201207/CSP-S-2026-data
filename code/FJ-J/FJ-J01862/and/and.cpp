#include <bits/stdc++.h>

int main(){
	std::frepoen("and.in","r",stdin);
	std::freopen("and.out","w",stdout);
	int n,s,gg1[200005];
	std::cin>>n>>s;
	for(int i=1;i<=n;i++){
		std::cin>>gg1[i];
	}
	std::sort(gg1+1,gg1+n+1);
	std::cout<<gg1[s];
	
	return 0;
}
