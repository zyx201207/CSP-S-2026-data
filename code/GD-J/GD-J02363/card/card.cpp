#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 20;
int tong[N];
int hand[N],desk[N],ans[N],cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		cin>>hand[i];
	}
	
	for(int i = 1 ; i <= m ; i++){
		int x = n;//手上牌总数 
		for(int j = 1 ; j <= n ; j++){
			desk[i] = 0;
		}//初始化desk 
		for(int j = 1 ; j <= i-1 ; j++){
			cnt[j] = hand[j];
			hand[j] = 0;
		} //忽略i-1张牌 
		while(x){ 
			if(tong[desk[i]] >= 1){//收走 
				for(int i = 1 ; i <= n ; i++){
					desk[i] = 0;
				}	
				desk[i+1] = hand[i+1];
				tong[desk[i]] = 0;
			}
			desk[i] = hand[i];//放牌 
			tong[desk[i]]++;
			x--;
		}
		for(int j = 1 ; j <= n ; j ++){
				ans[desk[j]]++;
		}//桌上还剩的牌 
		for(int j = 1 ; j <= i-1 ; j++){
			hand[j] = cnt[j];
			cnt[j] = 0;
		}	
	}
	for(int i = 1 ; i <= m ; i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
