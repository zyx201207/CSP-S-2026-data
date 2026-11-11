#include<bits/stdc++.h>
using namespace std;
int a[500010];
int d[500010];
int f[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		
		//1.清零 
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		
		//2.开始发牌 
		for(int j=i;j<=n;j++){
			
			f[j]=a[j];//列入队列 
			
			//3.判断是否与前面重复 
			for(int k=i;k<=j-1;k++){
				if(f[k]==f[j]){//如果有那么将前面重复的牌及其右侧的所有牌都收走 
				
					for(int x=k;x<=j-1;x++){
						f[x]=0;//收走 
					}
					
				}
			}
			 
		}//结束发牌
		
		 
		//将剩余的牌计入数组 
		for(int j=i;j<=n;j++){
			if(f[j]!=0){
				d[f[j]]++;
			}
		} 
		
	}
	
	//输出 
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
