// /card/card.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<int> cards;
vector<int> dots;

template <typename T> void clean(vector<T>& p, T val){
	for (size_t i = 0;i < p.size();i ++){
		if (p[i] == val){
			p.erase(p.begin()+i, p.end());
		}
	}
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	cards.resize(n+1);
	cards[0] = 0;
	dots.resize(m+1);
	dots[0] = 0;
	for (int i = 1;i <= n;i ++) cin >> cards[i];
	
	// mScore[i]: 留有i点数的牌的场数 
	vector<int> mScore(m+1, 0);
	for (int i = 1;i <= n;i ++){
		vector<int> desk(0);
		/*
		cout << "New desk: ";
		for (auto j:desk) cout << j << " ";
		cout << "\n";
		// */
		for (int j = i;j <= n;j ++){
			clean(desk, cards[j]);
			desk.push_back(cards[j]);
		}
		
		/*
		cout << "Rest: ";
		for (auto j:desk) cout << j << " ";
		cout << "\n";
		
		// */
		for (auto j:desk){
			mScore[j] ++;
		}
	} 
	
	for (int i = 1;i <= m;i ++){
		cout << mScore[i] << " ";
	}
	
	return 0;
} 
