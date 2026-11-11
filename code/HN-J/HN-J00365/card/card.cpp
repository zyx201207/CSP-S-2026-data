#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin >> n;
	cin >> m;
	vector<int> cardi;
	vector<int> cot;
	for (int i = 0;i < m;i++){
		cot.push_back(0);
	}
	int temp;
	for (int i = 0;i < n;i++){
		cin >> temp;
		cardi.push_back(temp);
	}
	
	
	int tem;
	for (int x = n;x > 0;x--){
		vector<int> table;
		int talen = 0;
		for (int i = 0;i < x;i++){
			tem = -1;
			for (int j = talen - 1;j >= 0;j--){
				if (table[j] == cardi[j]){
					tem = j;
				}
			}	
						
			if (tem == -1){
				table.push_back(cardi[i]);
				talen++;
			}
			else {
				for (int j = 0;j < talen;j++){
					
					if (table[talen - 1] == cardi[i]){
						break;
					}
					table.pop_back();
					talen--;
				} 
			}
		}
		for (int i = 0;i < talen;i++){
			cot[table[i] - 1]++;
		}
		
	}
	for (int i = 0;i < m;i++){
		cout << cot[i] << ' ';
	}
	
	return 0;
}

