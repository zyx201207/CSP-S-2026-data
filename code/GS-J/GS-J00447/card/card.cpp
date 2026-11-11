#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r",stdin);
	freopen("card.out", "w",stdout);
	vector<int> card_message;
	int number_times;
	int cycle;
	vector<int> number_lists;
	vector<int> table_message;
	cin >> number_times;
	cin >> cycle;
	for (int i = 0; i < number_times; i++){
		int user_input;
		cin >> user_input;
		card_message.push_back(user_input);
	}
	for (int i =0;i < cycle; i++){
		for (int m = 1; m< card_message.size();m++){
		for(int tm = 0;tm < table_message.size();tm++){
		if (table_message[tm] == card_message[m]){
			for (int ci = tm;ci < table_message.size();ci++){
				table_message[ci + 1] == 0;
				
			} 
			table_message[tm] == card_message[m];
		}
		table_message.push_back(card_message[m]);}
		}
	}
	for (int i = 0; i < table_message.size(); i++){
		if (table_message[i] !=0){
			cout << table_message[i];
		}
	}
	
}
