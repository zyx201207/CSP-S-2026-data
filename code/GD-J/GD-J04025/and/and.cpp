#include<bits/stdc++.h>
using namespace std;
int mn=0,sj[200001],jc[200001]={},n;
void dfs(int m,int z){
	if(z<mn){
		return ;
	}
	if(m==0||z==0){
		mn=max(z,mn);
		return ;
	}
	if(z!=0)printf("%d",z);
	for(int i=0;i<n;i++){
		if(jc[i]==0){
			jc[i]=1;
			dfs(m-1,z&sj[i]);
			jc[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&sj[i]);
	}
	dfs(m,0x7FFFFFFF);
	printf("%d",mn);
	return 0;
}
