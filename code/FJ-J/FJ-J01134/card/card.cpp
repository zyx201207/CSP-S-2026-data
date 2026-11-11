#include<bits/stdc++.h>
using namespace std;
int cards[1000086];
bool ifOK[3000086];
int n;
int m;
int cnt[1000086];
void play(int start){
	memset(ifOK,sizeof(ifOK),false);
	deque<int> cardsOnTable;
	cardsOnTable.push_back(cards[start]);
	ifOK[cards[start]] = true;//±Íº«∑√Œ  
	for(int i = start + 1;i <= n;i++){
		int curCard = cards[i];
//		cout << " vc ";
		if(ifOK[curCard] == true){
//			cout << "isTrue";
			while(cardsOnTable.back() != curCard){
				ifOK[cardsOnTable.back()] = false;
				cardsOnTable.pop_back();
//				cout << "pop";
			}
		}else{
			cardsOnTable.push_back(curCard);
			ifOK[curCard] == true;
		}
	}
	while(!cardsOnTable.empty()){
		cnt[cardsOnTable.front()]++;
//		cout << cardsOnTable.front();
		cardsOnTable.pop_front();
	}
	return;
}
int main(){
	ifstream fin("card.in");
	ofstream fout("card.out");
	memset(cnt,sizeof(cnt),0);
	fin >> n >> m;
	for(int i =1;i <= n;i++){
		fin >> cards[i];
	}
	for(int i = 1;i <= n;i++){
		play(i);
	}
	for(int i = 1;i <= m;i++){
		
		fout << cnt[i] << " ";
	}
	return 0;
} 
