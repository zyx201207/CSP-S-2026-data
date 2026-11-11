#include<bits/stdc++.h>
using namespace std;
int c1, s1, w1, c2, s2, w2, ans3, ans4;
string sr;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> sr;
	c1 = (sr[0] - '0') * 10 + sr[1] - '0';
	cin >> sr;
	s1 = (sr[0] - '0') * 10 + sr[1] - '0';
	w1 = sr[2] - 'A';
	cin >> sr;
	c2 = (sr[0] - '0') * 10 + sr[1] - '0';
	cin >> sr;
	s2 = (sr[0] - '0') * 10 + sr[1] - '0';
	w2 = sr[2] - 'A';
	if(w1 > w2)swap(w1, w2);
	ans3 = c1 == c2 && s1 == s2 && (w1 <= 2 && w2 <= 2 || w1 > 2 && w2 > 2);
	ans4 = c1 == c2 && s1 == s2 && (w1 == 0 && w2 == 1 || w1 == 1 && w2 == 2 || w1 == 3 && w2 == 5);
	printf("%d%d%d%d", c1 == c2, c1 == c2 && s1 == s2, ans3, ans4);
	return 0;
}
