#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ca[600000]={};//牌堆 
	int ans[400000]={};
	for(int i=0;i<n;i++)cin>>ca[i];
	for(int g=0;g<n;g++){//每局游戏 
		int pai[400000]={};//牌数
		int place[600000]={};//位置 
		for(int i=g;i<n;i++){//出牌 
			if(pai[ca[i]]==1){//取牌 
				for(int j=place[ca[i]];j<i;j++)pai[ca[j]]=0;
			}
			place[ca[i]]=i;
			pai[ca[i]]=1; 
		}
		for(int i=1;i<=m;i++)if(pai[i]==1)ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
