#include<bits/stdc++.h>
const int t=2e5+2;
int n,m,nums[t],M,Min;
using namespace std;
void dfs(int rc,int no,int ans){
	if(no>3 || rc>n) return;
	if(no==3){
		M=max(M,ans);
//		cout<<"M:"<<M<<"\n"; 
		return;
	} 
	for(int i=rc+1;i<=n;i++){
		dfs(i,no+1,ans&nums[i]);
	}
	return;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
//	bool A=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
//		if(log2(nums[i]+1)!=int(log2(nums[i]+1))) A=0;
		if(m==2){
			for(int j=1;j<i;j++){
				M=max(M,nums[i]&nums[j]);
			}
		}else if(m==1){
			M=max(M,nums[i]);
		}else if(m==n && i>1){
			nums[1]&=nums[i];
		}
	}
	if(m==n) M=nums[1];
//	else if(n<=20 && m!=2 && m!=1){
	else if(m!=2 && m!=1){
		dfs(1,1,nums[1]);
	}
	printf("%d",M);
	
	return 0;
} 
