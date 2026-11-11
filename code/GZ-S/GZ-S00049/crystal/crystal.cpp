//张仕林 GZ-S00049 
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[5000000];
int ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=i-1;++j){
			if(a[j]>a[j+1]){
				int c=a[j+1];
				a[j+1]=a[j];
				a[j]=c;
			}
		}
	}
	for(int i=2;i<=n;++i){
		int cont=m;//剩余操作次数 
		int num=0;//现阶段答案 
		for(int j=1;j<=i;++j){
			if(cont>=a[i]-a[j]){
				cont-=a[i]-a[j];
				num++; 
			}else{
				break;
			}
		}
		if(num>ans)ans=num;
		if(num<ans)break;
	}
	printf("%d",ans);
//	for(int i=1;i<=n;++i){
//		printf("%d ",a[i]);
//	}
	return 0;
}
