#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n;
	int m;
	cin >> n;
	cin >> m;
	vector<int> ani;
	for (int i = 0;i < m;i++){
		ani.push_back(0);
	}
	int temp;
	for (int i = 0;i < n;i++){
		cin >> temp;
		for (int j = 0;j < m;j++){
			if (temp > ani[j]){
				ani[j] = temp;
				break;
			}
		}
		
		for (int x = 0;x < m - 1;x++){
			for (int j = 0;j < m - x - 1;j++){
				if (ani[j] > ani[j+1]){
					temp = ani[j+1];
					ani[j+1] = ani[j];
					ani[j] = temp;
				}
			}
		}
	}
	int ano = ani[0];
	if (m == 2){
		cout << ani[0] and ani[1];
	}
	else if (m == 3){
		cout << ani[0] and ani[1] and ani[2];
	}
	else if (m == 1){
		cout << ani[0];
	}
	else if (m == 7){
		cout << ani[0] and ani[1] and ani[2] and ani[3] and ani[4] and ani[5] and ani[6];
	}
	else if (m == 10){
		cout << ani[0] and ani[1] and ani[2] and ani[3] and ani[4] and ani[5] and ani[6] and ani[7] and ani[8] and ani[9];
	}
	else if (m == 11){
		cout << ani[0] and ani[1] and ani[2] and ani[3] and ani[4] and ani[5] and ani[6] and ani[7] and ani[8] and ani[9] and ani[10];
	}
	else{
		for (int i = 1;i < m;i++){
			ano = ano and ani[i];
		}
		cout << ano;
	}
	
	return 0;
}

