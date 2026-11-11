#include<bits/stdc++.h>
using namespace std;
int n,m,a[550000],ans[330000],card[330000];
int l[330000][2],l1[550000];//l[i][1]表示这张牌存在于场上，l[i][2]表示这张牌的位置
//l1[i]场上第i张牌是什么
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int k=1;
	
	while(k<=n){
		int cnt=0;
		
		
		for(int i=1;i<=m;i++){//初始化
			for(int j=1;j<=2;j++){
				l[i][j]=0;
			}
		}
		for(int i=k;i<=n;i++){
			l1[i]=0;
		}
		
		for(int i=k;i<=n;i++){
			
			if(l[a[i]][1]==0){//没被删除，场上唯一 
				cnt++;
				l[a[i]][1]=1;//记录此牌已存在 
				l[a[i]][2]=cnt;//记录此牌位置 
				l1[cnt]=a[i];//这张牌是什么  
			}else{//存在
				for(int j=l[a[i]][2];j<=cnt;j++){//删除卡牌 i是当前删除的牌的编号 
					l[l1[j]][1]=0;//删除存在 
				}
				cnt++;
				l[a[i]][1]=1;//加入新牌
				l[a[i]][2]=cnt;//记录此牌位置 
				l1[cnt]=a[i];//这张牌是什么 
			}
		}
		for(int i=1;i<=m;i++){
			if(l[i][1]==1) ans[i]++;
		}
		k++;
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
