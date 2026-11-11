#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b[500005];
long long wan[500005];//记忆是否有放入过 
long long man[500005];//记忆是否有在游戏结束后留下 

queue<int> xz;
stack<int> zh;
//
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		xz.push(b[i]);
		
	}
	if(n==1){
		if(b[1]==1) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n+5;i++) wan[i]=-1;
	for(int i=1;i<=n+5;i++) man[i]=-1;
	
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			cin>>b[i];
			xz.push(b[i]);
			
		}
		for(int i=1;i<=n+5;i++) wan[i]=-1;
		for(int i=1;i<=n+5;i++) man[i]=-1;
			//跳过
		for(int i=1;i<=j-1;i++){
			xz.push(xz.back());
			xz.pop();
		}	
			//
		for(int i=j;i<=n;i++){//输入
			int a=xz.back();
			if(wan[xz.back()]==0){//没重复 
				wan[xz.back()]=1;
			}else{//重复了 
				xz.pop();
				while(zh.top()!=a){
					xz.push(zh.top());
					zh.pop();
				}
				xz.push(zh.top());
				zh.push(a);
			}
			
					
			//记下留下的牌 
			while(!zh.empty()){
				man[zh.top()]++; 
				zh.pop();
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<man[i]<<" "; 
	}
		 	
				

	return 0;
} 
//4 3 1 2 1 3
//10 3 3 1 2 1 3 2 3 1 2 1

