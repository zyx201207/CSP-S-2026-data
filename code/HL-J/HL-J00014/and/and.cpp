#include<bits/stdc++.h>
using namespace;
int n,m,a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin>>n>>m;
	for(int i =1;i<=n;i++){
		std::cin>>a[i];
	}
	if(m==1){
		int maxn = -1;
		for(int i = 1;i<=n;i++){
			if(a[i]>maxn){
				maxn = a[i];
			}
		}
		std::cout<<maxn;
	}
	if(m==2){
		int maxn = -1,maxn2 = -2;
		for(int i = 1;i<=n;i++){
			if(a[i]>maxn){
				maxn2 = maxn;
				maxn = a[i];
			}
		}
		std::cout<<maxn2;		
	}
	if(m==n||m==n-1){
		cout<<"0";
	}
	return 0;
}