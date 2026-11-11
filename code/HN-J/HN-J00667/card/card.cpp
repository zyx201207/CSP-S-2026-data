#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long n, m;
	cin >> n >> m;
	string card;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		card += c;
	}
//	cout << card;
	for (int i = 1; i <= n; i++){
		string s;
		for (int j = i; j <= n; j++){
			string s1 = s;
			s1 += card[j-1];
			if (s1.find(card[j-1]) != j-1){
				s.erase(s1.find(card[j-1]));
				s += card[j-1];
			}else {
				s += card[j-1];
			}	
		}
		for (int k = 0; k < s.size(); k++){
			a[s[k]-'0']++;
		}
	}
	for (int i = 1; i <= n; i++){
		if (a[i] != 0) cout << a[i] << " ";
	}
	return 0;
}
 
 
