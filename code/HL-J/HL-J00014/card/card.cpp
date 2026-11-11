#include<bits/stdc++.h>
using namespace;
int n,m,a[100000],s[100000],ans[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin>>n>>m;
	int z = 0;
	while(s[2]==0){
		z++;
		for(int i = 1;i<=n;i++){
			std::cin>>a[i];
		}
		bool w = 0;
		for(int i = z;i<=n;i++){
			for(int j = 1;j<=i;j++){
				if(s[j]==a[i]){
					w = j;
				}
			}
			if(w = 0){
				s[i] = a[i];
			}
			else{
				if(i>=w){
					s[i] = 0;
				}
			}
			ans[s[i]]++;
		}
		for(int j = 1;j<=n;j++){
			std::cout<<ans[j]<<" ";
		}	
	}
	
	return 0;
}