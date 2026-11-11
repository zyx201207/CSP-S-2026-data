#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
const int M=3e5;
struct table_{
	int m;//点数
	int num;//序号
};
table_ table[N];
int use[N];//-1清走了，1桌子上，0排堆中
int paidui[N];
int m,n,tabnum;
bool is_k(int k){
	for(int i=n;i>=1;i--){
		if(table[i].m==k){
			return false;
		}
	}
	return true;
}
int find_k(int k){
	for(int i=n;i>=1;i--){
		if(table[i].m==k){
			return i;
		}
	}
}
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>paidui[i];
	}
	for(int q=1;q<=n;q++){
		for(int i=q;i<=n;i++){
			if(is_k(paidui[i])){
				table[n-tabnum].m=paidui[i];
				table[n-tabnum].num=i;
				use[i]=1;
				tabnum++;//牌数
			}else{
				tabnum=n-find_k(paidui[i]);
				for(int j=n-tabnum+1;j<=find_k(paidui[i]);j++){
					use[table[j].num]=-1;
					table[j].m=0;
					table[j].num=0;
				}
				table[n-tabnum].m=paidui[i];
				table[n-tabnum].num=i;
			}
		}
		for(int i=1;i<=tabnum;i++){
			for(int j=1;j<=m;j++){
				if(table[n-i+1].num==j){
					ans[j]++;
					break;
				}
			}
		}
		memset(table,0,sizeof(table));
		memset(use,0,sizeof(use));
		tabnum=0;
		
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
	}
	return 0;
}
