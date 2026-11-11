#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int tong[500010],ans[500010];//数的位置，为 0 则为未插入 
int q[500010];//插入队列 
int idx;

int main(){
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i-1]>a[i]){
				flag=false;
			}
		}
	}
//	if(flag){
//		for(int i=1;i<=m;i++){
//			cout<<i<<' ';
//		} 
//		return 0;
//	}
	for(int i=1;i<=n;i++){
		idx=1;//从 1 开始写入 
		memset(tong,0,sizeof(tong));
		memset(q,0,sizeof(q)); 
		for(int j=i;j<=n;j++){
			if(tong[a[j]]){//已经存在
				int temp=tong[a[j]];
				for(int k=tong[a[j]]+1;k<idx;k++){//k 是位置 
					tong[q[k]]=0;
				}
				idx=temp;
			}
			q[idx]=a[j];//插入当前卡牌 
			tong[a[j]]=idx;//标记当前卡牌 
			idx++;//待写位 
		}
		for(int j=1;j<=m;j++){
			if(tong[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
