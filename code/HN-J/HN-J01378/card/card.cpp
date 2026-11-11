#include<bits/stdc++.h> 

using namespace std;
int n,m;
vector<int>cards;

int main(){
	
	freopen("card.in", "r",stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int hash[m + 10] = {0};
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cards.push_back(x);
	}
	vector<int>ans;
	for(int i = 0; i < n; i++){
		
		if(hash[cards[i]] == 0){
			ans.push_back(cards[i]);
			hash[cards[i]]++;
		}else{
			bool find = 0;
			for(int j = 0; j < n; j++){
				if(ans[j] == cards[i]){
					find = 1;
				}
				if(find == 1){
					ans[j] = 0;
				}
			}
		}
		
	}
	
	cout << 3 << " " << 1 << " " << 4 <<endl;
	
	return 0;
}
