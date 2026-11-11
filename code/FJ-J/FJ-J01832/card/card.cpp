#include<bits/stdc++.h>
using namespace std;

int n,m;
int len_t;  //桌子上卡数 
int used_num;  //局内可用卡数 
int using_cards;  //本剧可用卡数 
int arr[500005];  //原来卡点数
int use[500005];  //每局用的卡
int table[500005];  //记录桌子上卡的点数 
//stack <int> table;
int num_over[300005];  //结束后牌桌上剩余卡的点数的数量

void g_Mem(){
	used_num--;
	using_cards=n-used_num+1;
	for(int i=1;i<=len_t;i++){
		table[i]=0;
	} 
	len_t=0;
	for(int i=using_cards;i<=n;i++){
		use[i]=arr[i];
	}
}

void c_Add(){
	for(int i=1;i<=len_t;i++){
		num_over[table[i]]++;
	}
}


 int main(){
 	freopen("r","card.in",stdin);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>arr[i];
	}
	used_num=n;
	while(used_num>0){
		for(int i=using_cards;i<=n;i++){
			++len_t;
			table[len_t]=use[i];
			for(int j=1;j<len_t;j++){
				if(table[j]==use[i]){
					int tmp=len_t;
					for(int k=j;j<tmp;k++){
						table[i]=0;
					}
				}
			}
		}
		c_Add();
		g_Mem(); 
	}
	for(int i=1;i<=m;i++){
		if(num_over[i]){
			cout<<num_over[i]<<' ';
		}
	}
	freopen("w","card.out",stdout);
	return 0;
 }
