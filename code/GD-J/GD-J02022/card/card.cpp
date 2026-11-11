#include <bits/stdc++.h>
using namespace std;

int number[100005] = {0};
int card[100005] = {0};
int flag[10005] = {0};
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n = 0 , m = 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> number[i];
	}
	
	for(int i = 0;i < n;i++){
		
		for(int j = i;j < n;j++){
			int tf = 0;
			for(int k = 0;k < j - i + 1;k++){
				if(card[k] == number[j]){
					tf = k + 1;
					break;
				}
			}
			if(!tf){
				//cout << tf << endl;
				card[j-i] = number[j];
			}
			else{
				//cout << tf << endl;
				card[tf - 1,n] = {0};
				card[tf - 2] = number[j];
			}
		}
		for(int i = 0;i < n;i++){
			//cout << card[i] << ' ';
			for(int k = 1;k <= m;k++){
				if(card[i] == k){
					++flag[k-1];
				}
			}
		}
		for(int d = 0;d < 10005;d++){
			card[d] = 0;
		}
		//cout << endl;
	}
	for(int i = 0;i < m;i++){
		cout << flag[i] << ' ';
	}
	return 0;
}
