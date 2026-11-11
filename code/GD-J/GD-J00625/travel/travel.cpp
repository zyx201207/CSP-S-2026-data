#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000\n";
		return 0;
	}
	cout << "1";
	string h1 = "";h1 += s1[0];h1 += s1[1];
	string h2 = "";h2 += s2[0];h2 += s2[1];
	if(h1 != h2){
		cout << "000\n";
		return 0;
	}
	cout << "1";
	char ch1 = s1[2], ch2 = s2[2];
	int p1 = ('A' <= ch1 && ch1 <= 'C' ? 1 : 0);
	int p2 = ('A' <= ch2 && ch2 <= 'C' ? 1 : 0);
	if(p1 != p2){
		cout << "00\n";
		return 0;
	}
	cout << "1";
	if(ch1 > ch2)swap(ch1, ch2);
	if((ch1 == 'A' && ch2 == 'B') || (ch1 == 'B' && ch2 == 'C') || (ch1 == 'D' && ch2 == 'F')){
		cout << "1\n";
	}
	else cout << "0\n";
	
	return 0;
}
