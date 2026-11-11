#include <iostream>
using namespace std;
int c[30005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[50005], b[30005];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	//打牌 
	for(int i = 1; i <= n; i++){
		//打n局 
		for(int j = i; j <= n; j++){
			//第i局的牌 
			if(c[a[j]] == 0){
				//新卡牌 
				c[a[j]] = j;
			}
			else{
				//消消乐 
				for(int l = 1; l <= m; l++){
		    		if(c[l] > c[a[j]]){
		    			c[l] = 0;
					}
	            }
			}
		}
		for(int l = 1; l <= m; l++){
			//打完了，计数 
			if(c[l] > 0){
				b[l]++;
			}
		}
		for(int l = 1; l <= m; l++){
			//洗牌 
		    c[l] = 0;
	    }
	}
	for(int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
} 
