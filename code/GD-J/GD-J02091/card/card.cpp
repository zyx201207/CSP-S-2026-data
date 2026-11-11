#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005],sum[300005],now[500005],sy,ai;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//第i场游戏 
		sy=1;
		for(int j=i;j<=n;j++){//打第j张牌 
			//出牌
			ai=a[j];
			now[sy]=0;
			now[sy]=ai;
			if(num[a[j]]==0){ 
				num[a[j]]++;
				
			}
			else{//弃牌 
				for(int i1=1;i1<=sy;i1++){
					if(now[i1]==a[j]){
						for(int j1=i1+1;j1<=sy;j1++){
							num[now[j1]]--;
							now[j1]=0;
						}
						sy=i1;
						break;
					}
				}
				
			}
			sy++;
		}
		for(int j=1;j<=sy;j++){
			sum[now[j]]++;
			now[j]=0;
			
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<sum[m]<<" ";
	}
	return 0;
} 
