#include<bits/stdc++.h>
using namespace std;

int n,m,a[300001]={},zm[300001]={},shiyong[300001]={};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int step=0;
	for(int i=1;i<=n;i++){//n局游戏 
		for(int j=1;j<=step;j++){//清理桌面 
			zm[j]=0;
		}
		step=0;
		for(int j=i;j<=n;j++){//发牌 
			bool y=false;
			for(int v=1;v<=step;v++){//看是否有重复 
				if(zm[v]==a[j]){
					for(int l=v+1;l<=step;l++){
						zm[l]=0;
						y=true;
					}
					step=v;
				}
			}
			if(!y){
				step++;
				zm[step]=a[j];
			}
		}
		for(int j=1;j<=step;j++){//记录剩余牌 
			shiyong[zm[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<shiyong[i]<<' ';
	} 
	return 0;
}
