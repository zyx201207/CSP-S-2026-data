#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve_other(int a, int b, vector<int> cards){
	vector<int> hav(b + 1, 0);
	
	for(int i = 0; i != a; ++ i){
		vector<int> desk, wh(b + 1, -1);
		
		for(int j = i; j != a; ++ j){
			int p = cards[j];
			
			if(wh[p] != -1)
				while(wh[p] < desk.size())
					wh[desk.back()] = -1,
					desk.pop_back();
			
			wh[p] = desk.size();
			desk.push_back(p);
		}
		
		for(const auto &j : desk)
			++ hav[j];
	}
	
	for(int i = 1; i <= b; ++ i)
		cout << hav[i] << " ";
}

bool can_20(int a, vector<int> &cards){
	for(int i = 1; i != a; ++ i)
		if(cards[i] < cards[i - 1])
			return false;
	
	return true;
}

void solve_20(int a, int b, vector<int> &cards){
	vector<int> hav(b + 1, 0);
	
	for(int i = 0; i != a; ++ i)
		++ hav[cards[i]];
	
	for(int i = 1; i <= b; ++ i)
		hav[i] += hav[i - 1],
		cout << hav[i] << " ";
}

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	#endif
	
	int a, b;
	cin >> a >> b;
	
	vector<int> cards(a);
	
	for(auto &i : cards)
		cin >> i;
	
	if(can_20(a, cards))
		solve_20(a, b, cards);
	else
		solve_other(a, b, cards);
	
	return 0;
}
