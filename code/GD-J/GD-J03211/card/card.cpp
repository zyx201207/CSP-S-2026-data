#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],cnt[M];
void mn(int k){
	int vis[M],viss[N];//vis下标为ai的数据，存ai的下标   viss下标为ai的下标，存ai的数据
	for(int z=k;z<=n;++z){
		if(vis[a[z]]!=0){//如果出现过 
			for(int j=vis[a[z]]+1;j<=z-1;++j){//删除他与他右边的所有数 
				cnt[viss[j]]--; 
				vis[viss[j]]=0;
				viss[j]=0;
			}
			//删除重复
			viss[vis[a[z]]]=0;
			viss[z]=a[z];
			vis[a[z]]=z;
		}
		else{
			viss[z]=a[z];
			vis[a[z]]=z;
			++cnt[a[z]];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cout<<a[i];
	}
	for(int i=1;i<=n;++i){
		mn(i);//进入模拟 
	}
	for(int i=1;i<=m;++i){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
