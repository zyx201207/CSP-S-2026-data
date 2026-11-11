#include<bits/stdc++.h>
using namespace std;
int N,M,A[500010];
int ans[300010];
bool flag[300010],f[500010]; 
map<int,int> mp;
void method_one(){
	for(int i=1;i<=N;i++){
		memset(flag,false,sizeof(flag));
		for(int j=i;j<=N;j++){
			if(flag[A[j]]){
				bool find=false;
				for(int k=i;k<=j;k++){
					if(A[k]==A[j]&&f[k])
						find=true;
					if(find){
						flag[A[k]]=false;
						f[k]=false;
						}
					}
				}
			flag[A[j]]=true;
			f[j]=true;
		} 
		for(int j=i;j<=N;j++)
			if(flag[A[j]]){
				ans[A[j]]++;
				flag[A[j]]=false;
			}
	}
	for(int i=1;i<=M;i++)
		printf("%d ",ans[i]);
	return ;
}
void method_two(){
	for(int i=1;i<=N;i++)
		ans[A[i]]++;
	for(int i=1;i<=N;i++)
		if(A[i]!=A[i-1])
			ans[A[i]]+=ans[A[i-1]];
	for(int i=1;i<=M;i++)
		printf("%d ",ans[i]);
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&N,&M); 
	bool q=true;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		if(A[i]<A[i-1]) 
			q=false;
	}
	if(N<=500){
		method_one();
		return 0;
	}
	if(q){
		method_two();
		return 0;
	}
	return 0;
} 
