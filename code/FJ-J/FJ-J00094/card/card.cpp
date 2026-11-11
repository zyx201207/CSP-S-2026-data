#include<bits/stdc++.h>
using namespace std;
int type[300001];//花色 
int num[1000001];//每个排位对应的牌，即牌堆 
int sum[1000001];
int s[100001];
bool check(int x,int y){
	for(int q=0;q<y;q=q+1){
		if(num[q]==x){
			for(int p=q+1;p<=y;p=p+1){
				num[p]=0;
			}
			return q;//返回q 的值，即以q为起点q开始重新出牌 
		}
	}
	return y;
}//x为此时的牌，y为此时总共有y张牌，函数用于判断此时x有没有在牌堆num里 
int main(){
	int m;
	int n;
	int d=0;
	cin>>n>>m; 
	int z=0;//此时的牌数 
	int k=0;
	for(int i=1;i<=n;i=i+1){
		cin>>sum[i];
	}
	
	for(int i=1;i<=m;i=i+1){
		
		for(int j=1;j<=n;j=j+1){
			for(int l=d+1;l<=n;l=l+1){
				num[z]=sum[l];
				z=check(num[z],z);
				z=z+1;
			}
			for(int l=1;l<=z;l=l+1){
				if(num[l]==i){
					s[i]=s[i]+1;
				}
			}
			z=0;
			d=d+1;
		}
		cout<<s[i]<<" ";
		d=0;
	}
	return 0;
} 
