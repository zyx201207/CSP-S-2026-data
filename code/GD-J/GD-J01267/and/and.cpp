#include<bits/stdc++.h>
int n,m,chose[2^10]={0,},num[2^10]={0,},sum=0,max=-1,chosed[2^10]={0,};
void dfs(int u){
	if(u==m){
		sum=chose[0];
		for(int i=1;i<u;i++){
			sum&=chose[i];
		}
		if(sum>max){
			max=sum;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(chosed[i]==0){
			chose[u]=num[i];
			chosed[i]=1;
			dfs(u+1);
			chosed[i]=0;
			chose[u]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	std::cin>>n>>m;
	for(int i=0;i<n;i++){
		std::cin>>num[i];
	}
	std::cout<<max;
}
