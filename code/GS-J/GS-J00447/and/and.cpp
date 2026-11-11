#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r",stdin);
	freopen("and.out", "w",stdout);
	int number_times;
	int choise_number;
	vector<int> number_lists;
	cin >> number_times;
	cin >> choise_number;
	vector<int> max_number;
	max_number.push_back(0);
	for(int i = 0; i < number_times; i++){
		int user_input;
		cin >> user_input;
		for(int i=0;i <max_number.size(); i++){
			if (max_number.size() < choise_number){
				
				
				max_number.push_back(user_input);
				i = max_number.size();
			
			}
			if(max_number[i] == user_input){
				if(max_number.size() != i){
					i = max_number.size();
					}
			}
			if(max_number[i] < user_input){
				if(max_number.size() != i){
				
				max_number[i] = user_input;
				i = max_number.size();
		}
			}
			


		}
			}		
	
	int add_number = max_number[0];

 	for (int m=1; m<choise_number;m++){

		add_number = add_number || max_number[m];
		

	}
	cout << add_number;
}
