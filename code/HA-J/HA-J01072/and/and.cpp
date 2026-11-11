#include<bits/stdc++.h>

using namespace std;

	 int l_m,l_n;
	 
	 long long vis[2000060],l_a[2000060],max1;
	 void sl013(long long idk,int long long zhi,long long k,long long l_mm){
	 	if(k==l_mm){
	 		max1=max(max1,zhi);
	 		return;
		 }
	 	for(int i=idk;i<=l_n;i++){
	 		if(!vis[i]){
	 			vis[i]=1;
	 			sl013(i+1,zhi&l_a[i],k+1,l_mm);
	 			vis[i]=0;
			 }
		 }
	 }
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 scanf("%d%d",&l_n,&l_m);
	 for(int i=1;i<=l_n;i++){
	 	scanf("%lld",&l_a[i]);
	 }
	 if(l_n<=20)
	 sl013(1,2147483647,0,l_m);
	 
	 printf("%lld",max1);
	return 0;
}
