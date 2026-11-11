//GZ-J00568 遵义市第四初级中学 罗俊毅 
#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a],sum[b+1]={};
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		int at[b+1]={};
		int arr[50001]={};
		int weizhi=i;
		for(int j=i;j<a;j++){
			if(at[c[j]]==0){
				arr[weizhi]=c[j];
				at[c[j]]=weizhi+1;
			}
			else{
				for(int k=at[c[j]];k<j;k++){
					at[c[k]]=0;
					arr[k]=0;
				}
				weizhi-=(j-at[c[j]]+1);
				arr[weizhi]=c[j];
				at[c[j]]=weizhi+1;
				weizhi++;
			}
			weizhi++;
		}
		for(int i=0;i<weizhi;i++){
			sum[arr[i]]++;
		}
	}
	for(int i=1;i<=b;i++)printf("%d ",sum[i]);
	return 0;
}
