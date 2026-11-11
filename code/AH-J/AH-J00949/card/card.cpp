#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];//牌
int b[500005];//桌子
int c[300005];
signed main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){   //n次游戏
		for(int j=i;j<=n;j++){//取牌
			int asd=1;
			b[asd]=a[j];//打出牌
			for(int s=1;s<=asd;s++){//查重
				if(b[s]==a[j]){
					for(int as=s;as<=asd;as++){ //去重
						b[as]=0;
					}
					asd=s-1;
					b[asd]=a[j];//放右侧 
				}		
			}
		}//第i轮游戏结束
		for(int j=1;j<=m;j++){
			for(int s=1;s<=m;s++){
				if(b[s]==j){
					c[j]++;
				}
			}
		}//找在所有 n 局游戏中，有多少局结束时桌面上留有点数为 i 的牌	
		for(int j=1;j<=i;j++){
			b[j]=0;
		}		
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}

	return 0;
}
