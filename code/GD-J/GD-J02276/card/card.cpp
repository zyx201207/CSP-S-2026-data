#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
using namespace std;
stack<int> table;
queue<int> cards;
ifstream In("card.in");
ofstream Out("card.out");

int res[550000];
int n,m;
void print_cards(){
	while(cards.size()>0){
		cout << cards.front() << " ";
		cards.pop();
	}
	cout << endl;
}
void print_table(){
	while(table.size()>0){
		cout << table.top() << " ";
		table.pop();
	}
	cout << endl;
}

int main(){
	int hash[350000] = {0};
	In >> n >> m;
	for(int i = 1;i <= n;i++){
		int temp;
		In >> temp;
		cards.push(temp);
	}
	for(int i = 1;i <= n;i++){
		queue<int>t_cards = cards;
		for(int j = 1;j<=(i - 1);j++)t_cards.pop();
		while(t_cards.size() > 0){
			int id = t_cards.front();
			if(hash[id]){
				while(table.top()!=t_cards.front()){
					hash[table.top()] = 0;
					table.pop();
				}
				table.pop();
			}
			table.push(t_cards.front());
			hash[t_cards.front()] = 1;
			t_cards.pop();
		}
//		print_table();
		for(int i = 0;i < 350000;i++){
			res[i] += hash[i];
			hash[i] = 0;
		}
	}
	for(int i = 1;i<=m;i++){
		Out << res[i] << " ";
	}
	cout << endl;
	return 0;
}
